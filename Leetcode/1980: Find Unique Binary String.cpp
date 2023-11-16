class Solution {
public:
    int numToBin(string &s) {
        int res = 0;
        for (char c : s) {
            res <<= 1;
            res |= (c - '0');
        }
        return res;
    }

    string binToStr(int x, int n) {
        string res(n, '0');
        for (int i = 0; x; x /= 2) {
            res[i++] = (x%2 ? '1' : '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> m;
        for (auto &s : nums) m.insert(numToBin(s));
        
        int lim = (1<<n);
        for (int i = 0; i < lim; i++) {
            if (m.count(i)) continue;
            return binToStr(i, n);
        }

        string res(n, '1');
        return res;
    }
};