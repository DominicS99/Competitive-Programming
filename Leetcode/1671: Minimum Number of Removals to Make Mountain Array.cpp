// Did LIS both ways, then realized I had to skip indexes at the start and end if they couldn't create a mountain array.
// LIS includes current element both ways, hence the -1 to remove the duplicated element when computing the best answer.
typedef pair<int, int> pii;
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<pii> ans(n, {0, 0});

        vector<int> d;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(d.begin(), d.end(), nums[i]);
            if (it == d.end()) {
                d.push_back(nums[i]);
                ans[i].first = d.size();
            } else {
                *it = nums[i];
                ans[i].first = it-d.begin()+1;
            }
        }
        d.clear();

        for (int i = n-1; i >= 0; i--) {
            auto it = lower_bound(d.begin(), d.end(), nums[i]);
            if (it == d.end()) {
                d.push_back(nums[i]);
                ans[i].second = d.size();
            } else {
                *it = nums[i];
                ans[i].second = it-d.begin()+1;
            }
        }

        int res = 0, start = 1, stop = n-2;
        while (start < n && nums[start] <= nums[start-1]) start++;
        while (stop >= 0 && nums[stop] <= nums[stop+1]) stop--;

        for (int i = start; i <= stop; i++) {
            int curr = ans[i].first + ans[i].second - 1;
            res = max(res, curr);
        }

        return n-res;
    }
};
