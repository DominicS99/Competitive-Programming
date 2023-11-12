class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int high = max(nums1.back(), nums2.back());
        int low = min(nums1.back(), nums2.back());
        if (high < *max_element(nums1.begin(), nums1.end())) return -1;
        if (high < *max_element(nums2.begin(), nums2.end())) return -1;
        
        int pos1 = 0;
        for (int i = 0; i+1 < n; i++) {
            if (nums1[i] > nums1.back() || nums2[i] > nums2.back()) {
                pos1++;
                if (nums2[i] > nums1.back() || nums1[i] > nums2.back()) return -1;
            }
        }
        
        swap(nums1[n-1], nums2[n-1]);
        int pos2 = 1;
        for (int i = 0; i+1 < n; i++) {
            if (nums1[i] > nums1.back() || nums2[i] > nums2.back()) {
                pos2++;
                if (nums2[i] > nums1.back() || nums1[i] > nums2.back()) return -1;
            }
        }
        return min(pos1, pos2);
    }
};