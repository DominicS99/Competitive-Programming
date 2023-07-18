class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int res = 0, count = 0;
        int l = 0, r = tokens.size();
        while (l < r) {
            while (l < r && tokens[l] <= power) {
                power -= tokens[l++];
                count++;
            }
            if (!count) break;
            res = max(res, count);
            power += tokens[--r];
            count--;
        }

        return res;
    }
};
