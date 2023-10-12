#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int nums[2] = {0, 0};
    int i = 0;
    for (char c : s) {
        if (c == ')') continue;
        if (c == '(') {
            i++;
            continue;   
        }
        nums[i]++;
    }

    if (nums[0] != nums[1]) {
        cout << "fix\n";
    } else {
        cout << "correct\n";
    }
    return 0;
}