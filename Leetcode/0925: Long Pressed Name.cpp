class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (i < name.size() && j < typed.size()) {
            int countA = 1, countB = 1;
            while (++i < name.size() && name[i] == name[i-1]) countA++;
            while (++j < typed.size() && typed[j] == typed[j-1]) countB++;
            if (countA > countB || name[i-1] != typed[j-1]) return false;
        }
        return i == name.size() && j == typed.size();
    }
};