class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> res;
        string curr = "";
        for (char &c : target) {
            curr += 'a';
            res.push_back(curr);
            while (curr.back() != c) {
                curr.back()++;
                res.push_back(curr);
            }
        }
        return res;
    }
};
