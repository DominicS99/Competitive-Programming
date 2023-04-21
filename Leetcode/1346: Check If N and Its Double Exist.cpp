class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> s;
        for (auto &it : arr) s[it]++;
        for (auto &it : arr) {
            if (!it) continue;
            if (s.count(it*2)) return true;
        }
        return s[0] > 1;
    }
};
