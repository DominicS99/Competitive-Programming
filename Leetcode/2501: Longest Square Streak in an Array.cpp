class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int lim = *max_element(nums.begin(), nums.end());
        vector<int> d(lim+1, 0);
        for (auto &x : nums) d[x] = 1;

        int res = 0;
        for (int i = 0; i <= lim; i++) {
            if (!d[i]) continue;
            int curr = 0;
            for (long j = i; j <= lim; j *= j) {
                if (!d[j]) break;
                curr++;
            }
            res = max(res, curr);
        }
        return res < 2 ? -1 : res;
    }
};
