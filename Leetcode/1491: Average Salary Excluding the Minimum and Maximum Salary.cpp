class Solution {
public:
    double average(vector<int>& s) {
        int high = *max_element(s.begin(), s.end());
        int low = *min_element(s.begin(), s.end());
        double res = accumulate(s.begin(), s.end(), 0) - high - low;
        return res/(s.size()-2);
    }
};
