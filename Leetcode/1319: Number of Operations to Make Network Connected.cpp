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

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        parent.resize(n, -1);

        for (auto &it : connections) {
            int a = findSet(it[0]);
            int b = findSet(it[1]);
            if (a != b) {
                if (a < b) swap(a, b);
                parent[b] = a;
                n--;
            }
        }

        return n - 1;
    }
};
