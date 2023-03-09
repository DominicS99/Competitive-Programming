class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int m = l + (r-l)/2;
            int count = 0;
            for (auto &c : piles) {
                count += (c%m ? c/m + 1 : c/m);
            }

            if (count > h) l = m+1;
            else r = m;
        }

        return l;
    }
};
