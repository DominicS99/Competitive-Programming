typedef long long ll;

class Solution {
public:
    ll minimumTime(vector<int>& time, int totalTrips) {
        ll l = 1, r = (ll)totalTrips * (*min_element(time.begin(), time.end()));
        while (l < r) {
            ll m = l + (r-l)/2;
            ll curr = 0;
            for (auto &it : time) {
                curr += m/it;
                if (curr >= totalTrips) break;
            }

            if (curr < totalTrips) {
                l = m+1;
            } else {
                r = m;
            }
        }

        return l;
    }
};
