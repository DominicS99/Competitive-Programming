typedef long long ll;

class Solution {
public:
    ll maximumImportance(int n, vector<vector<int>>& roads) {
        ll res = 0;
        vector<ll> counts(n, 0);

        for (auto &it : roads) {
            counts[it[0]]++;
            counts[it[1]]++;
        }
        sort(counts.begin(), counts.end());
        
        for (int i = 1; i <= n; i++) {
            res += (i * counts[i-1]);
        }

        return res;
    }
};
