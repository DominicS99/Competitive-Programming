class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int a = abs(fx-sx), b = abs(fy-sy);
        if (t < max(a, b)) return false;
        if (max(a, b) == 0 && t == 1) return false;
        return true;
    }
};