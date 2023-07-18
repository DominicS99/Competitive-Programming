class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int curr = 0;
            for (int j = 0; j < n; j++) {
                if (boxes[j] == '0') continue;
                curr += abs(i-j);
            }
            res[i] = curr;
        }

        return res;
    }
};

// Can also solve in O(n). Good to note, but this problem had lenient constraints
/*
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        int curr = 0, r = 0, l = 0;
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '0') continue;
            curr += i;
            r++;
        }

        for (int i = 0; i < n; i++) {
            res[i] = curr;
            if (boxes[i] == '1') r--, l++;
            curr += l-r;
        }
        return res;
    }
};
*/
