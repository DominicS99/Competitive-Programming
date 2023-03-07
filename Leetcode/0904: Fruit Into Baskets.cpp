class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int res = 0;
        int l = 0, r = 0, i;
        int rightmostFruit = fruits[0];
        for (i = 0; i < n; i++) {
            if (fruits[i] != fruits[l] && fruits[i] != rightmostFruit) {
                res = max(res, i-l);
                l = r;
                r = i;
                rightmostFruit = fruits[i];
            } else if (fruits[i] != fruits[r]) {
                r = i;
            }
        }

        return max(res, i-l);
    }
};
