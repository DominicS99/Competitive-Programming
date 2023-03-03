class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int end = haystack.size()-n;
        for (int i = 0; i <= end; i++) {
            if (haystack.substr(i, n) == needle) return i;
        }
        return -1;
    }
};
