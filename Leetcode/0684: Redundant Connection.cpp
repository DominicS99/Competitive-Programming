class Solution {
public:
    vector<int> parent;
    int findSet(int v) {
        if (parent[v] == -1) {
            return parent[v] = v;
        }
        if (parent[v] == v) return v;
        return parent[v] = findSet(parent[v]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.assign(edges.size()+1, -1);
        vector<int> res;
        for (auto &it : edges) {
            int a = findSet(it[0]);
            int b = findSet(it[1]);
            if (a == b) {
                res = it;
                break;
            }
            if (a < b) swap(a, b);
            parent[b] = a;
        }
        return res;
    }
};
