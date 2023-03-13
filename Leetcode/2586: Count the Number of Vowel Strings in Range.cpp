class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int res = 0;
        string s = "aeiou";

        for (int i = left; i <= right; i++) {
            string curr = words[i];
            int n = curr.length();
            if (s.find(curr[0]) != string::npos && s.find(curr[n-1]) != string::npos) {
                res++;
            }
        }

        return res;
    }
};
