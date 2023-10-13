class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int l = 0, r = 0;
        while (r < n) {
            while (r < n && s[r] != ' ') r++;
            int tr = r-1;
            while (l < tr) swap(s[l++], s[tr--]);
            r++;
            l = r;
        }
        return s;
    }
};