/*
  An example: 128
  
    You need to check 3 different numbers for 128: 1, 12, 128.
    1 in decimal = 1 in binary, only has one 1 digit.
    12 in decimal = 1100 in binary, has two 1 digits.
    128 in decimal = 10000000 in binary, only has one 1 digit.
  
    The most 1 digits in any of these numbers is 2, therefore 2 is the answer.
*/

#include <iostream>
using namespace std;

int main() {
  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    string tempstr;
    int res = 0;
    
    for (int i = 0; i < s.length(); i++) {
      tempstr += s[i];
      int tempNum = stoi(tempstr);
      int curr = 0;
      
      while (tempNum > 0) {
        if (tempNum%2 == 1) curr++;
        tempNum /= 2;
      }
      res = max(res, curr);
    }

    cout << res << endl;
  }
  return 0;
}
