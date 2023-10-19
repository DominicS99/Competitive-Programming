class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a, b;
        for (char c : s) {
            if (c != '#') a += c;
            else if (!a.empty()) a.pop_back();
        }
        for (char c : t) {
            if (c != '#') b += c;
            else if (!b.empty()) b.pop_back();
        }
        return a == b;
    }
};