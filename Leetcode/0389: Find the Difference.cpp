class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> a(26, 0), b(26, 0);
        for (char c : s) a[c-'a']++;
        for (char c : t) b[c-'a']++;
        for (int i = 0; i < 26; i++) {
            if (a[i] < b[i]) return i+'a';
        }
        return 'z';
    }
};