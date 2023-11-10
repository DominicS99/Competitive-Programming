class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res;
        if (!a) {
            res.assign(b, 'b');
        } else if (!b) {
            res.assign(a, 'a');
        } else if (a > b) {
            res = strWithout3a3b(a-2, b-1) + "baa";
        } else if (b > a) {
            res = strWithout3a3b(a-1, b-2) + "abb";
        } else {
            res = strWithout3a3b(a-1, b-1);
            if (!res.empty() && res.back() == 'b') {
                res += "ab";
            } else {
                res += "ba";
            }
        }
        return res;
    }
};