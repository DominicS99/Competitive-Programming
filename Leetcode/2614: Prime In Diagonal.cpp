/*
  V2:
  Update: Turns out LeetCode compiles all the test cases together rather than individually, so it was creating the entire sieve every time. Good to know, but still annoyed with this problem lol
*/

vector<bool> primes;
class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        if (primes.empty()) {
            int MAX = 1e7;
            primes.assign(MAX, 1);
            primes[0] = 0;
            primes[1] = 0;
            
            int lim = sqrt(MAX);
            for (int i = 2; i < lim; i++) {
                if (!primes[i]) continue;
                for (int j = i*i; j < MAX; j+=i) {
                    primes[j] = 0;
                }
            }
        }

        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (primes[nums[i][i]]) res = max(res, nums[i][i]);
            if (primes[nums[n-i-1][i]]) res = max(res, nums[n-i-1][i]);
        }
        return res;
    }
};

/*
  V1:
  It seems the better intuition is to calculate the prime in O(sqrt(n)) for all diag tiles (300*2-1), and skip the O(sqrt(n)) calculation if it isn't necessary by checking if our current res is already bigger.
  
  This problem should be fine with a 1e7 sieve, and yet it TLEs. Having an easy be that restrictive is very strange.
*/

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int MAX = 4000001;
        vector<bool> primes(MAX, 1);
        primes[0] = 0;
        primes[1] = 0;
        int lim = sqrt(MAX);
        for (int i = 2; i < lim; i++) {
            if (!primes[i]) continue;
            for (int j = i*i; j < MAX; j+=i) {
                primes[j] = 0;
            }
        }
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (primes[nums[i][i]]) res = max(res, nums[i][i]);
            if (primes[nums[n-i-1][i]]) res = max(res, nums[n-i-1][i]);
        }
        return res;
    }
};
