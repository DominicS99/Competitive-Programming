class Solution {
public:
    bool valid(char &c) {
        if (c >= 'A' && c <= 'Z') c += 32;
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.length()-1;
        while (l < r) {
            if (valid(s[l]) && valid(s[r])) {
                if (s[l] != s[r]) return false;
                l++;
                r--;
            } else if (!valid(s[l])) {
                l++;
            } else {
                r--;
            }
        }
        return true;
    }
};
