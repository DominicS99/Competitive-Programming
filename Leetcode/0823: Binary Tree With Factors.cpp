typedef long long ll;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD = 1e9+7;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int res = 0;

        unordered_map<int, ll> m;
        for (auto &x : arr) m[x] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i]%arr[j]) continue;
                if (!m.count(arr[i]/arr[j])) continue;
                int temp = (m[arr[j]] * m[arr[i]/arr[j]]) % MOD;
                m[arr[i]] = (m[arr[i]] + temp) % MOD;
            }
            res = (res + m[arr[i]]) % MOD;
        }
        
        return res;
    }
};