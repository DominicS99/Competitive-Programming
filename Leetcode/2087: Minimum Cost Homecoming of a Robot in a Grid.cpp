class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int res = 0 - rowCosts[startPos[0]] - colCosts[startPos[1]];
        if (startPos[0] > homePos[0]) swap(startPos[0], homePos[0]);
        if (startPos[1] > homePos[1]) swap(startPos[1], homePos[1]);
        for (int i = startPos[0]; i <= homePos[0]; i++) {
            res += rowCosts[i];
        }
        for (int i = startPos[1]; i <= homePos[1]; i++) {
            res += colCosts[i];
        }
        return res;
    }
};