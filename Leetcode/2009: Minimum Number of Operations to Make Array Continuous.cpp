class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int res = n-1;
        unique(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());

        queue<int> q;
        for (auto &x : nums) {
            while (!q.empty() && q.front()+(n-1) < x) {
                q.pop();
            }
            q.push(x);
            res = min(res, n-(int)q.size());
        }
        return res;
    }
};