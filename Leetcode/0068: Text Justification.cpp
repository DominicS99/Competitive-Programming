class Solution {
public:
    string addRow(vector<string> &row, int maxWidth, int len) {
        string res = row[0];
        if (row.size() > 1) {
            int extra = (maxWidth-len) % (row.size()-1);
            int lim = (maxWidth-len) / (row.size()-1);
            for (int i = 1; i < row.size(); i++) {
                for (int j = 0; j < lim; j++) res += ' ';
                if (i <= extra) res += ' ';
                res += row[i];
            }
        }
        for (int i = res.length(); i < maxWidth; i++) res += ' ';
        return res;
    }

    string finRow(vector<string> &row, int maxWidth) {
        string res = row[0];
        for (int i = 1; i < row.size(); i++) {
            res += ' ';
            res += row[i];
        }
        for (int i = res.length(); i < maxWidth; i++) res += ' ';
        return res;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> row, res;
        int len = 0;
        for (string &w : words) {
            if (row.size() + len + w.length() > maxWidth) {
                res.push_back(addRow(row, maxWidth, len));
                row.clear();
                len = 0;
            }
            row.push_back(w);
            len += w.length();
        }
        if (!row.empty()) res.push_back(finRow(row, maxWidth));
        return res;
    }
};