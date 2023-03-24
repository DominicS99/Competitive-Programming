class Solution {
public:
    vector<int> parent;

    int findSet(int v) {
        if (parent[v] == -1) {
            parent[v] = v;
            return v;
        }
        if (v == parent[v]) return v;
        return parent[v] = findSet(parent[v]);
    }

    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n+1, -1);
        vector<int> vals(n+1, 1e9);
        for (auto &it : roads) {
            int a = findSet(it[0]);
            int b = findSet(it[1]);
            if (a != b) {
                if (a < b) swap(a, b);
                parent[b] = a;
            }
            vals[a] = vals[b] = min(it[2], min(vals[a], vals[b]));
        }

        return vals[n];
    }
};
