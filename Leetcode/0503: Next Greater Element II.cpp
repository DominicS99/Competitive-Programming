// Slower, but more concise solution.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(), size = n*2;
        vector<int> res(n, -1);
        stack<int> s;

        for (int i = 0; i < size; i++) {
            while (!s.empty() && nums[s.top()] < nums[i%n]) {
                res[s.top()] = nums[i%n];
                s.pop();
            }
            s.push(i%n);
        }

        return res;
    }
};

/*
  Idea: Used a monotonic stack idea, but had some fun with the particular aspects of it
  Slightly better time complexity due to not completing the 2nd loop of the array
*/

/*
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
*/
