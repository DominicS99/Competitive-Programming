class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int l = 0, curr = 0;
        for (int r = 1; r < arr.size(); r++) {
            if (arr[l] > arr[r]) {
                curr++;
            } else {
                curr = 1;
                l = r;
            }
            if (curr == k) break;
        }
        return arr[l];
    }
};