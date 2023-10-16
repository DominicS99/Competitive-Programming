class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        for (int i = 0; i < rowIndex; i++) {
            vector<int> curr = {1};
            for (int j = 0; j+1 < res.size(); j++) {
                curr.push_back(res[j] + res[j+1]);
            }
            curr.push_back(1);
            res = curr;
        }
        return res;
    }
};