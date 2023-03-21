class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> count(2, 0);
        for (int i = 0; n > 0; i++, n/=2) {
            if (n%2) count[i%2]++;
        }
        return count;
    }
};
