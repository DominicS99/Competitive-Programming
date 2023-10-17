class Solution {
public:
    int groups;
    vector<int> parent;

    int findSet(int v) {
        if (parent[v] == -1) {
            parent[v] = v;
        }
        if (parent[v] == v) return v;
        return parent[v] = findSet(parent[v]);
    }

    void unionSet(int a, int b) {
        a = findSet(a); b = findSet(b);
        if (a != b) {
            if (a > b) swap(a, b);
            parent[b] = a;
            groups--;
        }
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        groups = n;
        parent.assign(n, -1);
        vector<int> vis(n, 0);

        function<bool(int)> solve = [&] (int i) {
            if (vis[i] == 2) {
                vis[i] = 3;
                return true;
            }
            if (vis[i]) return false;
            vis[i] = 1;
            bool f = true;

            if (leftChild[i] != -1) {
                unionSet(i, leftChild[i]);
                f &= solve(leftChild[i]);
            }

            if (rightChild[i] != -1) {
                unionSet(i, rightChild[i]);
                f &= solve(rightChild[i]);
            }

            return f;
        };

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            if (!solve(i)) return false;
            vis[i] = 2;
        }

        return groups == 1;
    }
};