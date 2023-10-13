class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        if (m > n) return false;

        int a = 0;
        for (int b = 0; b < n; b++) if (s[a] == t[b]) a++;
        return a == m;
    }
};