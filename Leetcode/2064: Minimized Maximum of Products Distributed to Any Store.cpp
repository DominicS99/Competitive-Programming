typedef long long ll;
class Solution {
public:
    int helper(ll x, int n, vector<int>& quantities) {
        int temp = 0;
        for (auto &q : quantities) {
            temp += ceil((double)q/x);
        }
        return temp;
    }

    int solve(ll l, ll r, int n, vector<int>& quantities) {
        while (l < r) {
            ll m = l + (r-l)/2;

            if (helper(m, n, quantities) > n) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return l;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        double sum = 0;
        for (auto &x : quantities) sum += x;
        ll loLim = ceil(sum/n);
        
        return solve(loLim, *max_element(quantities.begin(), quantities.end()), n, quantities);
    }
};
