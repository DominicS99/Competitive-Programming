class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int l = 1, r = arr[1]-arr[0];
        while (l < r) {
            int m = l + (r-l)/2;

            bool f = true;
            for (int i = 1; i < n; i++) {
                if (arr[i] - arr[i-1] <= m) {
                    f = false;
                    break;
                }
            }

            if (f) {
                l = m+1;
            } else {
                r = m;
            }
        }

        vector<vector<int>> res;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i-1] == l) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};
