class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long res = 0;
        int n = maxHeights.size();
        for (int i = 0; i < n; i++) {
            long long curr = maxHeights[i];
            int l = i-1, r = i+1;
            int lHeight = maxHeights[i], rHeight = maxHeights[i];
            while (l >= 0) {
                lHeight = min(lHeight, maxHeights[l]);
                curr += lHeight;
                l--;
            }
            while (r < n) {
                rHeight = min(rHeight, maxHeights[r]);
                curr += rHeight;
                r++;
            }
            res = max(res, curr);
        }
        return res;
    }
};