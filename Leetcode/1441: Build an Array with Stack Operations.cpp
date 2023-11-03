class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        for (int i = 1, j = 0; i <= n; i++) {
            res.push_back("Push");
            if (target[j] != i) {
                res.push_back("Pop");
                continue;
            }
            if (++j == target.size()) break;
        }
        return res;
    }
};