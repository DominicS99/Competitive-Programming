/*
Used BFS logic to traverse grid based on min priority queue.
Used min priority queue to store each value and coordinates while conducting BFS.
Used DP logic to save results, that way each query can be completed in O(1) time.
*/

typedef pair<int,int> pii;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int limit = grid.size() * grid[0].size();
        vector<int> dir = {0,1,0,-1,0};
        vector<int> res;
        vector<int> memo(1000002, limit);

        priority_queue<pair<int,pii>> pq;
        pq.push({grid[0][0], {0, 0}});
        int points = 0, value = 0;
        
        while (!pq.empty()) {
            pii curr = pq.top().second;
            pq.pop();
            if (grid[curr.first][curr.second] > 1000000) continue;
            while (value < grid[curr.first][curr.second]) {
                memo[value] = points;
                value++;
            }
            points++;
            grid[curr.first][curr.second] = 1000001;

            for (int i = 0; i < 4; i++) {
                int r = curr.first + dir[i];
                int c = curr.second + dir[i+1];

                if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) continue;
                if (grid[r][c] > 1000000) continue;
                pq.push({grid[r][c]*-1, {r, c}});
            }
        }

        for (auto it : queries) {
            res.push_back(memo[it-1]);
        }

        return res;
    }
};
