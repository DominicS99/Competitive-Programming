#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    string s;
    while (getline(cin, s)) {
        for (char &c : s) c = tolower(c);
        if (s.find("problem") != string::npos) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}