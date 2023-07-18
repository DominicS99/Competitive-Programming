class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int l = 0, r = 0;
        if (nums1.back() < nums2.back()) swap(nums1, nums2);
        while (l < nums1.size()) {
            if (r == nums2.size() || nums1[l] < nums2[r]) {
                l++;
            } else if (nums1[l] > nums2[r]) {
                r++;
            } else {
                return nums1[l];
            }
        }
        int low = min(nums1[0], nums2[0]);
        int high = max(nums1[0], nums2[0]);
        return low*10 + high;
    }
};
