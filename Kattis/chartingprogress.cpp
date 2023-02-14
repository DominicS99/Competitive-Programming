#include <iostream>
using namespace std;

int main() {
  // Fast I/O - not necessary here, but it doesn't hurt
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  string s;
  int left, mid, i;
  int star, end;
  
  getline(cin, s);
  while (!s.empty()) {
    // Reset variables for new test case
    star = 0;
    end = 0;

    // For each line...
    while (!s.empty()) {
      // Count how many '*' there are
      for (char &c : s) {
        if (c == '*') star++;
      }

      // Print '.' for everything left of first '*' location
      // Print '*' for star - end
        // End = previous star count
      // Print '.' until you've filled the entire row
      left = s.size()-star;
      mid = star-end;

      for (i = 0; i < left; i++) cout << ".";
      for (i = 0; i < mid; i++) cout << "*";
      for (i = 0; i < end; i++) cout << ".";
      cout << endl;

      // Continues until string s is an empty line
      end = star;
      getline(cin, s);
    }

    // Continues until there are 2 empty lines in a row
    cout << endl;
    getline(cin, s);
  }

  return 0;
}
