class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int a = (left.size() == 0 ? 0 : *max_element(left.begin(), left.end()));
        int b = (right.size() == 0 ? n : *min_element(right.begin(), right.end()));
        return max(a, n-b);
    }
};