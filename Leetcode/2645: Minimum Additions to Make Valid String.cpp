class Solution {
public:
    int addMinimum(string word) {
        vector<char> d = {'a','b','c'};
        int n = word.length();
        int res = 0;
        for (int i = 0, l = 0; i < n; i++) {
            if (word[i] != d[l%3]) {
                i--;
                res++;
            }
            l++;
        }
        if (word[n-1] == 'a') res += 2;
        else if (word[n-1] == 'b') res += 1;
        return res;
    }
};
