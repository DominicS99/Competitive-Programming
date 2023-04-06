class Solution {
public:
    vector<int> parent;

    int findSet(int v) {
        if (parent[v] == -1) {
            parent[v] = v;
            return v;
        }
        if (parent[v] == v) return v;
        return parent[v] = findSet(parent[v]);
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [&](vector<int> & a, vector<int> &b) {
            return a[2] < b[2];
        });

        parent.assign(n, -1);
        parent[0] = 0;
        parent[firstPerson] = 0;
        int l = 0;
        while (l < meetings.size()) {
            int time = meetings[l][2];
            set<int> unsure;

            while (l < meetings.size() && meetings[l][2] == time) {
                int a = findSet(meetings[l][1]);
                int b = findSet(meetings[l][0]);
                if (a != b) {
                    if (!b) swap(a, b);
                    parent[b] = a;
                }
                unsure.insert(meetings[l][1]);
                unsure.insert(meetings[l][0]);
                l++;
            }

            for (auto &x : unsure) {
                if (findSet(x)) parent[x] = x;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!parent[i]) res.push_back(i);
        }
        return res;
    }
};
