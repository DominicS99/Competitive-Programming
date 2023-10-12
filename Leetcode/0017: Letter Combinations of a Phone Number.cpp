class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> res;
        if (digits.empty()) return res;
        
        vector<vector<char>> letters(10);
        letters[2] = {'a', 'b', 'c'};
        letters[3] = {'d', 'e', 'f'};
        letters[4] = {'g', 'h', 'i'};
        letters[5] = {'j', 'k', 'l'};
        letters[6] = {'m', 'n', 'o'};
        letters[7] = {'p', 'q', 'r', 's'};
        letters[8] = {'t', 'u', 'v'};
        letters[9] = {'w', 'x', 'y', 'z'};

        string curr;
        function<void(int)> solve = [&] (int i) {
            if (i == n) {
                res.push_back(curr);
                return;
            }

            for (char &c : letters[digits[i]-'0']) {
                curr += c;
                solve(i+1);
                curr.pop_back();
            }
        };

        solve(0);
        return res;
    }
};