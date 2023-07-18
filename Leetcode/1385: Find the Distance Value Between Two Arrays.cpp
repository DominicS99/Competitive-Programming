class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int res = 0;
        for (auto &x : arr1) {
            bool f = true;
            int l = 0, r = arr2.size();
            while (l < r) {
                int m = l + (r-l)/2;
                if (arr2[m] > x+d) {
                    r = m;
                } else if (arr2[m] < x-d) {
                    l = m+1;
                } else {
                    f = false;
                    break;
                }
            }
            if (f) res++;
        }
        return res;
    }
};
