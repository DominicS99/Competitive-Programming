class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int m = nums1.size(), n = nums2.size();
        int a = 0, b = 0;

        while (a < m) {
            if (b == n || nums1[a] < nums2[b]) {
                merged.push_back(nums1[a++]);
            } else {
                merged.push_back(nums2[b++]);
            }
        }
        while (b < n) merged.push_back(nums2[b++]);

        int tot = m+n;
        if (tot%2) return merged[tot/2];
        return (merged[tot/2 - 1] + merged[tot/2]) / 2.0;
    }
};