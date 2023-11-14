/*
Annoying
*/

class Solution {
public:
    bool solve(double res) {
        return abs(24-res) <= 1e-9;
    }

    bool solve(double a, double b) {

        if (solve(a+b)) return true;
        if (solve(a-b)) return true;
        if (solve(a*b)) return true;
        return solve(a/b);
    }

    bool solve(double a, double b, double c) {
        if (solve(a+b, c)) return true;
        if (solve(a-b, c)) return true;
        if (solve(a*b, c)) return true;
        if (solve(a/b, c)) return true;

        if (solve(a, b+c)) return true;
        if (solve(a, b-c)) return true;
        if (solve(a, b*c)) return true;
        return solve(a, b/c);
    }

    bool solve(double a, double b, double c, double d) {
        if (solve(a+b, c, d)) return true;
        if (solve(a-b, c, d)) return true;
        if (solve(a*b, c, d)) return true;
        if (solve(a/b, c, d)) return true;

        if (solve(a, b+c, d)) return true;
        if (solve(a, b-c, d)) return true;
        if (solve(a, b*c, d)) return true;
        if (solve(a, b/c, d)) return true;

        if (solve(a, b, c+d)) return true;
        if (solve(a, b, c-d)) return true;
        if (solve(a, b, c*d)) return true;
        return solve(a, b, c/d);
    }

    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(), cards.end());
        do {
            if (solve(cards[0], cards[1], cards[2], cards[3])) return true;
        } while (next_permutation(cards.begin(), cards.end()));
        return false;
    }
};