/*
  Idea: Any single throw can only produce a set amount of results.
  - Find those results and store them.
  - There's only 3 darts, so you can do an n^3 search over all combinations.
    - 20 + 10 + 7 = 37 combos, therefore 37^3 search.
  - Get the result ready once you've found a combination that works.
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> nums;
  for (int i = 0; i < 21; i++) {
    nums.insert(i);
    nums.insert(i*2);
    nums.insert(i*3);
  }
  
  vector<string> res;
  for (int first : nums) {
    for (int second : nums) {
      for (int third : nums) {
        if (first + second + third != n) continue;
        vector<int> vals = {third, second, first};
        for (auto &curr : vals) {
          if (curr == 0) continue;
          if (curr%3 == 0) {
            res.push_back("triple " + to_string(curr/3));
          } else if (curr%2 == 0) {
            res.push_back("double " + to_string(curr/2));
          } else {
            res.push_back("single " + to_string(curr));
          }
        }
        
        n = 0;
      }
    }
  }

  if (n > 0) {
    cout << "impossible" << endl;
  } else {
    for (auto & it : res) cout << it << endl;
  }

  return 0;
}
