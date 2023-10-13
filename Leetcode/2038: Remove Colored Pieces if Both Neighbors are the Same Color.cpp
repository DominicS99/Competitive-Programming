class Solution {
public:
    int n;

    bool check(string &colors, char c, int &i) {
        for (; i+1 < n; i++) {
            if (c == colors[i-1] && c == colors[i] && c == colors[i+1]) {
                return true;
            }
        }
        return false;
    }

    bool winnerOfGame(string colors) {
        n = colors.size();
        for (int a = 1, b = 1; ; a++, b++) {
            if (!check(colors, 'A', a)) return false;
            if (!check(colors, 'B', b)) return true;
        }
        return false;
    }
};