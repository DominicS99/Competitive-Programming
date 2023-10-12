class Solution {
public:
    int distanceBetweenBusStops(vector<int>& dist, int a, int b) {
        int n = dist.size();

        auto solve = [&] (int l, int r) {
            int res = 0;
            for (int i = l; i != r; i = (i+1)%n) res += dist[i];
            return res;
        };

        return min(solve(a, b), solve(b, a));
    }
};