class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        int l = 0, r = 0;
        if (nums1[nums1.size()-1][0] < nums2[nums2.size()-1][0]) swap(nums1, nums2);

        while (l < nums1.size()) {
            if (r == nums2.size() || nums1[l][0] < nums2[r][0]) {
                res.push_back(nums1[l++]);
            } else if (nums1[l][0] > nums2[r][0]) {
                res.push_back(nums2[r++]);
            } else {
                res.push_back({nums1[l][0], nums1[l++][1] + nums2[r++][1]});
            }
        }

        return res;
    }
};
