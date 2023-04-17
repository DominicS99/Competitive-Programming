class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int high = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        vector<bool> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = candies[i]+extraCandies >= high;
        }
        return res;
    }
};
