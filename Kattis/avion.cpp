#include <iostream>
using namespace std;

int main() {
    int n = 5;
    string s;
    string res;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (s.find("FBI") != string::npos) res += to_string(i) + " ";
    }
    
    if (res.empty()) {
        cout << "HE GOT AWAY!\n";
    } else {
        cout << res << "\n";
    }
    return 0;
}