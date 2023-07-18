class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        char a = -1, b = s[0];
        for (char &c : s) {
            if (c == '9') continue;
            a = c;
            break;
        }

        reverse(s.begin(), s.end());
        int high = 0, low = 0, inc = 1;
        for (char &c : s) {
            high += inc * (c == a ? 9 : c-'0');
            low += inc * (c == b ? 0 : c-'0');
            inc *= 10;
        }

        return high-low;
    }
};
