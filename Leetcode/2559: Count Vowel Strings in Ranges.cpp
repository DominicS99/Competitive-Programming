class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        string s = "aeiou";
        unordered_set<char> vowels;
        for (int i = 0; i < 5; i++) vowels.insert(s[i]);

        int n = words.size();
        vector<int> pref(n+1);
        pref[0] = 0;

        for (int i = 1; i <= n; i++) {
            if (vowels.count(words[i-1][0]) && 
              vowels.count(words[i-1][words[i-1].length()-1])) {
                pref[i] = 1;
            }
            pref[i] += pref[i-1];
        }

        vector<int> res;
        for (auto q : queries) res.push_back(pref[q[1]+1] - pref[q[0]]);

        return res;
    }
};
