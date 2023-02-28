class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.length();
        vector<int> res(n);
        long curr = 0;
        for (int i = 0; i < n; i++) {
            curr += word[i] - '0';
            curr %= m;
            res[i] = (curr == 0 ? 1 : 0);
            curr *= 10;
        }

        return res;
    }
};
