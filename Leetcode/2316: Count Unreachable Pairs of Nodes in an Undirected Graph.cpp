class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int findSet(int v) {
        if (parent[v] == -1) {
            parent[v] = v;
            size[v] = 1;
            return v;
        }
        if (parent[v] == v) return v;
        return parent[v] = findSet(parent[v]);
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n, -1);
        size.resize(n, 0);

        for (auto &it : edges) {
            int a = findSet(it[0]);
            int b = findSet(it[1]);

            if (a != b) {
                if (size[a] < size[b]) swap(a, b);
                parent[b] = a;
                size[a] += size[b];
            }
        }

        long long res = 0, cNodes = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                parent[i] = i;
                size[i] = 1;
            }
            if (i == parent[i]) {
                res += (size[i] * cNodes);
                cNodes += size[i];
            }
        }

        return res;
    }
};
