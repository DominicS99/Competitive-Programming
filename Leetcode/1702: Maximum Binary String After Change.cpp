class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();

        int l = -1;
        for (int i = 0; i < n; i++) {
            if (binary[i] == '1') continue;
            if (l == -1) {
                l = i;
            } else {
                binary[l++] = '1';
                swap(binary[l], binary[i]);
            }
        }
        
        return binary;
    }
};
