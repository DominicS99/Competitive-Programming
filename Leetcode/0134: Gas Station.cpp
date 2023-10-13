class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            if (gas[i] < cost[i]) continue;
            int g = gas[i]-cost[i];
            int j = i;
            while (g >= 0) {
                j = (j+1)%n;
                g += gas[j] - cost[j];
                if (j == i) return i;
            }
            if (j < i) break;
            i = j;
        }

        return -1;
    }
};