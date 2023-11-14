class Solution {
public:
    string sortVowels(string s) {
        string vowels = "AEIOUaeiou";
        vector<char> d;
        for (char &c : s) {
            if (vowels.find(c) == string::npos) continue;
            d.push_back(c);
        }
        sort(d.begin(), d.end());
        int i = 0;
        for (char &c : s) {
            if (vowels.find(c) == string::npos) continue;
            c = d[i++];
        }
        return s;
    }
};