class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int counter = 0;
        for (int &x : nums) {
            res += counter = x ? 0 : counter+1;
        }
        return res;
    }
};
