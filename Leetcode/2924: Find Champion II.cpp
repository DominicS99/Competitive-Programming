class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        for (auto &e : edges) vis[e[1]] = 1;
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            if (res == -1) res = i;
            else return -1;
        }
        return res;
    }
};