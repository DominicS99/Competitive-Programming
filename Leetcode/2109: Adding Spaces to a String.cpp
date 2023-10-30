class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int a = 0;
        string res;
        for (int i = 0; i < s.length(); i++) {
            if (a < spaces.size() && spaces[a] == i) {
                res += ' ';
                a++;
            }
            res += s[i];
        }
        return res;
    }
};