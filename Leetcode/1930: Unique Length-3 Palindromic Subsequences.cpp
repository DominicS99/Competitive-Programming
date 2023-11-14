typedef pair<int, int> pii;
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char, pii> m;
        for (int i = 0; i < n; i++) {
            if (!m.count(s[i])) {
                m[s[i]].first = i;
            }
            m[s[i]].second = i;
        }

        int res = 0;
        for (auto &[c, idxs] : m) {
            auto &[l, r] = idxs;
            unordered_set<char> used;
            for (int i = l+1; i < r; i++) {
                if (used.count(s[i])) continue;
                used.insert(s[i]);
                res++;
            }
        }

        return res;
    }
};