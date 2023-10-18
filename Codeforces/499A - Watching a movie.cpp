#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    int lim = 1e5+2;
    vector<int> d(lim, 0);

    int n, k; cin >> n >> k;
    while (n--) {
        cin >> a >> b;
        d[a]++; d[b+1]--;
    }

    for (int i = 1; i < lim; i++) {
        d[i] += d[i-1];
    }

    int res = 0;
    int curr = 0;
    for (int i = 1; i < lim; i++) {
        if (d[i]) {
            while (d[i++]) curr++;
            res += curr;
            curr = 0;
            i--;
        }
        curr = (curr+1)%k;
    }

    cout << res << "\n";
    
    return 0;
}