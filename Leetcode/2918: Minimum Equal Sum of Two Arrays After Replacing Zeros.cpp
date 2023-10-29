class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        bool a = 0, b = 0;
        long long sumA = 0, sumB = 0;
        for (auto &x : nums1) {
            sumA += x;
            if (x == 0) {
                a = 1;
                sumA++;
            }
        }
        for (auto &x : nums2) {
            sumB += x;
            if (x == 0) {
                b = 1;
                sumB++;
            }
        }
        if (sumA < sumB && !a) return -1;
        if (sumB < sumA && !b) return -1;
        return max(sumA, sumB);
    }
};