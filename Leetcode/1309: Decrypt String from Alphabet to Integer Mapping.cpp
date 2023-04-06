class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        for (int i = s.length() - 1; i > -1; i--) {
            if (s[i] == '#') {
                res.push_back(stoi(s.substr(i-2, 2)) + 'a'-1);
                i -= 2;
            } else {
                res.push_back(s[i]-'0' + 'a'-1);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
