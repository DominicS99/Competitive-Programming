class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        int n = access_times.size();
        map<string, vector<string>> m;
        for (auto &it : access_times) {
            m[it[0]].push_back(it[1]);
        }
        
        vector<string> res;
        for (auto &[s, d] : m) {
            sort(d.begin(), d.end());
            int currBest = 0;
            int curr = 0;
            int l = 0;
            int lF = stoi(d[0].substr(0, 2));
            int lR = stoi(d[0].substr(2, 2));
            for (int r = 0; r < d.size(); r++) {
                int xF = stoi(d[r].substr(0, 2));
                int xR = stoi(d[r].substr(2, 2));
                while (lF+1 < xF || (lF+1 == xF && lR <= xR)) {
                    curr--;
                    l++;
                    lF = stoi(d[l].substr(0, 2));
                    lR = stoi(d[l].substr(2, 2));
                }
                curr++;
                currBest = max(curr, currBest);
            }
            
            if (currBest >= 3) {
                res.push_back(s);
            }
        }
        
        return res;
    }
};