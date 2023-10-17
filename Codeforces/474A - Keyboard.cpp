#include <iostream>
using namespace std;

int main() {
    char d; cin >> d;
    string s; cin >> s;

    string top = "qwertyuiop";
    string mid = "asdfghjkl;";
    string bot = "zxcvbnm,./";

    int dir = d == 'L' ? 1 : -1;

    for (char c : s) {
        for (int i = 0; i < top.size(); i++) {
            if (top[i] == c) cout << top[i+dir];
            if (mid[i] == c) cout << mid[i+dir];
            if (bot[i] == c) cout << bot[i+dir];
        }
    }

    return 0;
}