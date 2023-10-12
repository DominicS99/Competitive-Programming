class Solution {
public:
    int n;
    void filterSpace(string &s) {
        int i;
        for (i = 0; i < n; i++) {
            if (s[i] != ' ') break;
        }
        s = s.substr(i);
        n = s.length();
    }

    void onlyDigits(string &s) {
        int i;
        for (i = 0; i < n; i++) {
            if (s[i] != '0') break;
        }
        s = s.substr(i);
        n = s.length();

        for (i = 0; i < n; i++) {
            if (s[i] < '0' || s[i] > '9') break;
        }
        s = s.substr(0, i);
        n = s.length();
    }

    int convertToInt(string &s, bool sign) {
        long long LIM = (1<<30), res = 0;
        LIM *= 2;

        reverse(s.begin(), s.end());
        long long digit = 1;
        for (int i = 0; i < min(n, 11); i++) {
            long long temp = s[i]-'0';
            res += temp * digit;
            digit *= 10;
        }
        for (int i = 11; i < n; i++) {
            if (s[i] != '0') {
                res = LIM;
                if (sign) return res * -1;
                return res-1;
            }
        }

        if (res >= LIM) {
            res = LIM;
            if (sign) return res * -1;
            return res-1;
        }
        return res * (sign ? -1 : 1);
    }

    int myAtoi(string s) {
        n = s.length();
        filterSpace(s);
        if (s.empty()) return 0;

        bool sign = (s.front() == '-');
        if (s.front() == '+' || s.front() == '-') s = s.substr(1);
        onlyDigits(s);
        return convertToInt(s, sign);
    }
};