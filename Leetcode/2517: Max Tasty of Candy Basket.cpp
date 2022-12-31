/*
  Checked hint to realize this was a Binary Search problem, from there it was pretty self-explanatory. 
  Took me a while to remember the technicalities of the algorithm, I'll need to do more practice with it.
*/

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int l = 0, r = price[n-1];
        
        while (l < r) {
            int m = l+(r-l)/2;
            int curr = 0, count = 1;
            for (int i = 1; i < n; i++) {
                curr += price[i] - price[i-1];
                if (curr >= m) {
                    curr = 0;
                    count++;
                }
            }

            if (count >= k) l = m+1;
            else r = m;
        }

        return l-1;
    }
};
