class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> m;
        m[0] = 0;
        for (auto &it : flowers) {
            m[it[0]]++;
            m[it[1]+1]--;
        }

        int buffer = 0;
        for (auto &[val, freq] : m) {
            buffer += freq;
            freq = buffer;
        }

        vector<int> res;
        for (auto &x : people) {
            auto it = m.lower_bound(x);
            if (it->first != x) it = prev(it);
            res.push_back(it->second);
        }
        return res;
    }
};