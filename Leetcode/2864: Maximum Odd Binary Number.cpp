class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int a = 0, b = 0;
        for (char c : s) {
            if (c == '0') a++;
            if (c == '1') b++;
        }
        string res;
        while (b > 1) {
            res += "1";
            b--;
        }
        while (a > 0) {
            res += "0";
            a--;
        }
        res += "1";
        return res;
    }
};