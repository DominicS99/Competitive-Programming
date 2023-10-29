class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int res = 0;
        for (auto x : nums) {
            int i = 0;
            while (x > 0) {
                if (x%2) m[i]++;
                x /= 2;
                i++;
            }
        }
        for (auto &[x, c] : m) {
            if (c >= k) res += (1<<x);
        }
        return res;
    }
};