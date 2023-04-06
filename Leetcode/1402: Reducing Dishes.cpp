class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        sort(s.rbegin(), s.rend());
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int curr = 0;
            for (int j = 0; j < i; j++) {
                curr += (i-j) * s[j];
            }
            if (curr < res) break;
            res = curr;
        }
        return res;
    }
};

// Can use a Prefix Sum idea to make it cleaner
/*
class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.rbegin(), s.rend());
        vector<int> res(2, 0);
        for (auto &x : s) {
            res[1] = max(res[1], res[1]+res[0]+x);
            res[0] += x;
        }
        return res[1];
    }
};
*/
