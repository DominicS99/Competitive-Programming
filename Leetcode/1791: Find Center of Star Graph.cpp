class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        auto & temp = edges[0][0];
        return temp == edges[1][0] || temp == edges[1][1] ? temp : edges[0][1];
    }
};
