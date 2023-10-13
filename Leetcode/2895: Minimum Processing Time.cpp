class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        sort(processorTime.rbegin(), processorTime.rend());
        int res = 0;
        int i = 0;
        for (auto &x : processorTime) {
            int curr = 0;
            for (int j = 0; j < 4; j++) {
                curr = max(curr, tasks[i++]+x);
            }
            res = max(res, curr);
        }

        return res;
    }
};