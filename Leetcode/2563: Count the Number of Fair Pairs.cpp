typedef long long ll;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ll res = 0;
        sort(nums.begin(), nums.end());

        for (auto it = nums.begin()+1; it != nums.end(); ++it) {
            ll lo = distance(it, lower_bound(it, nums.end(), lower- *prev(it)));
            ll hi = distance(it, upper_bound(it, nums.end(), upper- *prev(it)));
            res += hi-lo;
        }
        return res;
    }
};
