class Solution {
public:
    string addBinary(string a, string b) {
        int l = a.length()-1, r = b.length()-1;
        if (r > l) return addBinary(b, a);
        int carry = 0;

        while (l >= 0) {
            int curr = (a[l]-'0') + (r >= 0 ? (b[r]-'0') : 0) + carry;
            carry = curr > 1 ? 1 : 0;
            a[l] = (curr%2)+'0';
            l--; r--;
        }
        if (carry) a.insert(a.begin(), '1');

        return a;
    }
};
