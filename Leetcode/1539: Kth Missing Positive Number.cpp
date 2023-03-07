class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0, l = 0, n = arr.size(), i;
        for (i = 1; i <= 2000; i++) {
            if (l < n && arr[l] == i) {
                l++;
            } else {
                count++;
                if (count == k) break;
            }
        }
        return i;
    }
};
