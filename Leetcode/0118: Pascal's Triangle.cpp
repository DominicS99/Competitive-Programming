class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        while (res.size() < numRows) {
            vector<int> &prev = res.back();
            vector<int> curr(prev.begin(), prev.end());
            curr.push_back(0);

            for (int j = 0; j < prev.size(); j++) {
                curr[j+1] += prev[j];
            }
            res.push_back(curr);
        }
        
        return res;
    }
};
