class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](auto &x, auto &y) {
            if (__builtin_popcount(x) == __builtin_popcount(y)) return x < y;
            return __builtin_popcount(x) < __builtin_popcount(y);
        });
        return arr;
    }
};