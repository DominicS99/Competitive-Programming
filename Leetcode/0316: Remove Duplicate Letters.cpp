class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) m[s[i]] = i;

        vector<int> vis(26, 0);
        string res;
        for (int i = 0; i < s.length(); i++) {
            if (vis[s[i]-'a']) continue;
            while (!res.empty() && res.back() > s[i] && m[res.back()] > i) {
                vis[res.back()-'a'] = 0;
                res.pop_back();
            }
            res += s[i];
            vis[s[i]-'a'] = 1;
        }
        return res;
    }
};