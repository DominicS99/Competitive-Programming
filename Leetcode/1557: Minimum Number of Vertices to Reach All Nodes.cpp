class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> found(n, 1);
        for (auto &curr : edges) found[curr[1]] = false;

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (found[i]) res.push_back(i);
        }
        return res;
    }
};
