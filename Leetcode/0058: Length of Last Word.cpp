class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = s.length()-1;
        while (s[r] == ' ') r--;

        int res = r;
        while (r > -1 && s[r] != ' ') r--;

        return res-r;
    }
};
