#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int n; cin >> n;
    while (n--) {
        string curr; cin >> curr;
        for (int i = 0; i < s.length(); i++) {
            curr[i] = (curr[i]-'A')*(s[i]-'0')%26 + 'A';
        }
        cout << curr << "\n";
    }
    return 0;
}