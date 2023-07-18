class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0, t = 0;
        for (int & c : bills) {
            if (c == 5) {
                f++;
            } else if (c == 10) {
                if (!f) return false;
                t++; f--;
            } else {
                if (t && f) {
                    t--; f--;
                } else if (f > 2) {
                    f -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
