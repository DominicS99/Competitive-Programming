class Solution {
public:
    string simplifyPath(string path) {
        vector<string> names;
        string curr;
        for (char c : path) {
            if (c == '/') {
                if (!curr.empty()) names.push_back(curr);
                curr.clear();
            } else {
                curr.push_back(c);
            }
        }
        if (!curr.empty()) names.push_back(curr);

        vector<string> solved;
        for (auto &s : names) {
            if (s == "..") {
                if (!solved.empty()) solved.pop_back();
            } else if (s != ".") {
                solved.push_back(s);
            }
        }

        string res = "/";
        for (auto &s : solved) {
            res += s + "/";
        }
        if (res.size() > 1) res.pop_back();
        return res;
    }
};
