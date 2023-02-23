/*
  Idea: Used a monotonic stack idea, but had some fun with the particular aspects of it
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;

        int i;
        int high;
        int maximum = *max_element(nums.begin(), nums.end());

        for (i = 0; i < n; i++) {
            if (nums[i] == maximum) continue;

            while (i < n && nums[i] >= nums[(i+1)%n]) {
                s.push(i);
                i++;
            }

            if (i == n) break;
            high = nums[(i+1)%n];
            res[i] = high;

            while (!s.empty() && nums[s.top()] < high) {
                res[s.top()] = high;
                s.pop();
            }
        }
        
        while (!s.empty()) {
            if (nums[s.top()] < nums[i%n]) {
                res[s.top()] = nums[i%n];
                s.pop();
            } else {
                i++;
            }
        }

        return res;
    }
};
