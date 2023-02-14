/*
  Idea: 
  - Any even consecutive numbers will always have an even amount of odds or odd amount of odds
    - odd + odd + odd = new odd num
    - odd + odd + odd + odd = new even num
  - Any odd consecutive numbers can have x odds OR x+1 odds, therefore it can always be either
  
  But n only goes up to 10 so...could just hard code I guess lol.
*/

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n%2 == 0) {
    n = n/2;
    if (n%2 == 0) {
      cout << "Even";
    } else {
      cout << "Odd";
    }
  } else {
    cout << "Either";
  }

  cout << endl;
  return 0;
}
