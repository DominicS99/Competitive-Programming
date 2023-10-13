/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n;
        while (l < r) {
            int m = l + (r-l)/2;
            int leftNum = (m == 0 ? -1 : mountainArr.get(m-1));
            int rightNum = (m == n-1 ? 1e9+7 : mountainArr.get(m+1));
            int currNum = mountainArr.get(m);
            if (currNum > leftNum) l = m;
            if (currNum > rightNum) r = m;
        }
        
        int mid = l;
        l = 0, r = mid;
        while (l < r) {
            int m = l + (r-l)/2;
            if (mountainArr.get(m) < target) {
                l = m+1;
            } else {
                r = m;
            }
        }
        if (mountainArr.get(l) == target) return l;

        l = mid, r = n-1;
        while (l < r) {
            int m = l + (r-l)/2;
            if (mountainArr.get(m) > target) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return mountainArr.get(l) == target ? l : -1;
    }
};