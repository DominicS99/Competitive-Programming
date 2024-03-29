class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m--; n--;
        for (int size = m+n+1; size >= 0; size--) {
            int l = m < 0 ? -1e9 : nums1[m];
            int r = n < 0 ? -1e9 : nums2[n];
            if (l < r) {
                nums1[size] = r;
                n--;
            } else {
                nums1[size] = l;
                m--;
            }
        }
    }
};

// Secret Santa #1 solution
/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r = nums1.size()-1;
        m--, n--;
        while (n >= 0) {
            nums1[r--] = (m >= 0 && nums1[m] > nums2[n]) ? nums1[m--] : nums2[n--];
        }
    }
};
*/
