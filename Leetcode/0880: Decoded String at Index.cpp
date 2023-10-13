class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string temp;
        stack<pair<string, long long>> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                long long prev = (st.empty() ? 0 : st.top().second);
                long long curr = temp.length() + prev;
                long long times = min((long long)1e9, curr * (s[i]-'0'));
                st.push({temp, times});
                temp.clear();
                if (times >= k) break;
            } else {
                temp += s[i];
            }
        }
        if (!temp.empty()) {
            long long prev = (st.empty() ? 0 : st.top().second);
            long long curr = temp.length() + prev;
            long long times = min((long long)1e9, curr);
            st.push({temp, times});
        }
        while (!st.empty()) {
            auto [tempWord, extra] = st.top();
            st.pop();
            int totLen = tempWord.length();
            if (!st.empty()) totLen += st.top().second;
            k %= totLen;
            if (k == 0) k = totLen;

            if (k > totLen - tempWord.length()) {
                int idx = k - (totLen - tempWord.length()) - 1;
                string res = tempWord.substr(idx, 1);
                return res;
            }
        }
        return "";
    }
};