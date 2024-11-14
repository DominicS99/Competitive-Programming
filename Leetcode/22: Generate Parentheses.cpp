class Solution {
public:
    vector<string> res;
    string curr = "(";
    void solve(int unusedL, int remL) {
        if (unusedL == 0 && remL == 1) {
            curr += ")";
            res.push_back(curr);
            curr.pop_back();
            return;
        } 
        
        if (unusedL > 0) {
            curr += "(";
            solve(unusedL-1, remL+1);
            curr.pop_back();
        }

        if (remL > 0) {
            curr += ")";
            solve(unusedL, remL-1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        solve(n-1, 1);
        return res;
    }
};
