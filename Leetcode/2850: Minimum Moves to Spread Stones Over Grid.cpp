typedef pair<int, int> pii;
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = 3;
        vector<pii> starts, ends;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) ends.emplace_back(i, j);
                if (grid[i][j] > 1) {
                    for (int k = 1; k < grid[i][j]; k++) {
                        starts.emplace_back(i, j);
                    }
                }
            }
        }

        int res = 1e9;
        do {
            int curr = 0;
            for (int i = 0; i < starts.size(); i++) {
                curr += abs(starts[i].first - ends[i].first) + abs(starts[i].second - ends[i].second);
            }
            res = min(res, curr);
        } while (next_permutation(ends.begin(), ends.end()));
        return res;
    }
};