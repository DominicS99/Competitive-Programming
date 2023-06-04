#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int solve(int res, int a, int b, int x, int y) {
    if (res == -1) return -1;
    int l = a + (b*res), r = x + (y*res);
    
    while (l < r) {
        if (b <= y) return -1;
        res++;
        l += b; r += y;
    }
    return l == r ? res : -1;
}

int main() {
    vector<pii> curr;
    string s;
    int n, res = 1;
    cin >> n;
    
    while (n--) {
        int a = 0, b = 0;
        cin >> s;
        for (char c : s) {
            if (c == 's') a++;
            else if (c == 't') b++;
        }
        
        if (s.back() == '{') {
            curr.push_back({a, b});
        } else {
            auto [x, y] = curr.back(); curr.pop_back();
            res = a < x ? solve(res, a, b, x, y) : solve(res, x, y, a, b);
        }
    }
    
    cout << res << endl;
    return 0;
}
