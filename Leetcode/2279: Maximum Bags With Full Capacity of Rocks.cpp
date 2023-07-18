class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int a) {
        int n = cap.size();
        for (int i = 0; i < n; i++) {
            cap[i] -= rocks[i];
        }
        sort(cap.begin(), cap.end());
        int res = 0;
        for (int &x : cap) {
            if (x > a) break;
            a -= x;
            res++;
        }
        return res;
    }
};
