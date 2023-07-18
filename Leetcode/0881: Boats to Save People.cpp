class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int res = 0, l, r;
        for (l = 0, r = people.size()-1; l < r; r--) {
            if (people[l] + people[r] <= limit) l++;
            res++;
        }
        return l==r ? res+1 : res;
    }
};
