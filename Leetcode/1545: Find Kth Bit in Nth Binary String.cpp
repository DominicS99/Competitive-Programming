class Solution {
public:
    char findKthBit(int n, int k) {
        string res = "0";
        while (n-- > 1) {
            string temp;
            for (int i = res.length()-1; i >= 0; i--) {
                temp += (res[i] == '0' ? '1' : '0');
            }
            res += "1" + temp;
        }

        return res[k-1];
    }
};
