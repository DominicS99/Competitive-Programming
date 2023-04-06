class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int high = 1001, n = nums.size();
        vector<bool> primes(high, 1);
        for (int i = 2; i < sqrt(high); i++) {
            if (!primes[i]) continue;
            for (int j = i+i; j < high; j+=i) {
                primes[j] = 0;
            }
        }
        
        vector<int> res(n+1, 0);
        for (int i = 0; i < n; i++) {
            res[i+1] = nums[i];
            int lim = nums[i]-res[i];
            for (int j = lim-1; j > 1; j--) {
                if (!primes[j]) continue;
                res[i+1] = nums[i] - j;
                break;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (res[i] <= res[i-1]) return false;
        }
        return true;
    }
};
