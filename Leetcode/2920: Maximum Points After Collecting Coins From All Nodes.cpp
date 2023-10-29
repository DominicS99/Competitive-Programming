class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<int>> al(n);
        for (auto &it : edges) {
            al[it[0]].push_back(it[1]);
            al[it[1]].push_back(it[0]);
        }
        
        unordered_set<int> vis;
        vector<vector<int>> memo(n+1, vector<int>(20, -1e9));
        function<int(int, int)> solve = [&] (int i, int x) {
            auto &res = memo[i][x];
            if (res != -1e9) return res;
            if (x == 19) return res = 0;
            
            int curr = (coins[i]>>x);
            int tempA = curr-k, tempB = curr/2;
            
            for (auto &j : al[i]) {
                if (vis.count(j)) continue;
                vis.insert(j);
                tempA += solve(j, x);
                tempB += solve(j, x+1);
                vis.erase(j);
            }
            return res = max(tempA, tempB);
        };
        vis.insert(0);
        return solve(0, 0);
    }
};