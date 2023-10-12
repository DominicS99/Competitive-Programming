typedef pair<int, string> pxx;
class Solution {
public:
    string intToRoman(int num) {
        vector<pxx> m = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}};

        for (int i = 0; i < 5; i += 2) {
            auto [val, c] = m[i];
            m.emplace_back(val*4, c + m[i+1].second);
            m.emplace_back(val*9, c + m[i+2].second);
        }
        sort(m.rbegin(), m.rend());

        string res;
        for (auto &[val, c] : m) {
            for (; num >= val; num -= val) res += c;
        }
        return res;
    }
};