class Solution {
public:
    unordered_map<string, int> m;
    vector<int> memo;

    int solve(int i, vector<string>& words) {
        auto &res = memo[i];
        if (res != -1) return res;

        auto &s = words[i]; res = 1;
        for (int j = 0; j < s.length(); j++) {
            string temp = s.substr(0, j) + s.substr(j+1);
            if (m.count(temp)) res = max(res, solve(m[temp], words) + 1);
        }
        return res;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) m[words[i]] = i;
        memo.assign(n+1, -1);

        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, solve(i, words));
        return res;
    }
};