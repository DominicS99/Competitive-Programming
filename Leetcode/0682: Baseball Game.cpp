class Solution {
public:
    int calPoints(vector<string>& operations) {
        int res = 0, num;
        vector<int> curr;
        for (auto &s : operations) {
            if (s == "+") {
                int n = curr.size();
                num = curr[n-1] + curr[n-2];
                curr.push_back(num);
            } else if (s == "D") {
                num = curr.back() * 2;
                curr.push_back(num);
            } else if (s == "C") {
                num = -1 * curr.back();
                curr.pop_back();
            } else {
                num = stoi(s);
                curr.push_back(num);
            }
            res += num;
        }
        return res;
    }
};
