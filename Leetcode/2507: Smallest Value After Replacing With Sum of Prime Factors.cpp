class Solution {
public:
    int smallestValue(int n) {
        while (1) {
            int sum = 0;
            int curr = n;
            while (curr%2 == 0) {
                sum += 2;
                curr/=2;
            }

            for (int i = 3; i <= sqrt(n); i += 2) {
                while (curr%i == 0) {
                    sum += i;
                    curr /= i;
                }
            }
            if (curr > 2) sum += curr;

            if (sum == n) break;
            n = sum;
        }
        return n;
    }
};
