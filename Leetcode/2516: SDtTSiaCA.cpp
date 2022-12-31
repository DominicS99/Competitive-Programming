// Basically a 2 pointer implementation

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        if (target == words[startIndex]) return 0;
        int res = -1;
        int n = words.size();
        int l = (startIndex-1+n)%n, r = (startIndex+1)%n;
        for (int i = 0; i < n/2; i++) {
            if (words[l] == target || words[r] == target) {
                res = i+1;
                break;
            }
            l = (l-1+n)%n;
            r = (r+1)%n;
        }

        return res;
    }
};
