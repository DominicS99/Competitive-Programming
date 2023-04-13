class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int l = 0;
        stack<int> s;
        for (int x : pushed) {
            s.push(x);
            while (!s.empty() && popped[l] == s.top()) {
                s.pop();
                l++;
            }
        }

        while (!s.empty()) {
            if (s.top() != popped[l++]) return false; 
            s.pop();
        }
        return true;
    }
};
