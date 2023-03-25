class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> m;
        for (char c : s) {
            if (m.count(c)) return c;
            m.insert(c);
        }
        return s[0];
    }
};
