class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [&](auto &a, auto &b) {
            return a[1] > b[1];
        });
        int res = 0;
        for (int i = 0; i < boxTypes.size(); i++) {
            boxTypes[i][0] = min(boxTypes[i][0], truckSize);
            res += (boxTypes[i][0] * boxTypes[i][1]);
            truckSize -= boxTypes[i][0];
            if (truckSize == 0) break;
        }
        return res;
    }
};