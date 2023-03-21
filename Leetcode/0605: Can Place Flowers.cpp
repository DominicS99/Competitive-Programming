class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int __n = flowerbed.size();
        for (int i = 0; i < __n; i++) {
            if (flowerbed[i] == 1) continue;
            if (i > 0 && flowerbed[i-1] == 1) continue;
            if (i < __n-1 && flowerbed[i+1] == 1) continue;

            flowerbed[i] = 1;
            n--;
        }
        return n <= 0;
    }
};
