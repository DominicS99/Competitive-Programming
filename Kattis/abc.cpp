#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int num;
  vector<int> nums;
  string order;
  
  for (int i = 0; i < 3; i++) {
    cin >> num;
    nums.push_back(num);
  }

  sort(nums.begin(), nums.end());
  
  cin >> order;
  for (int i = 0; i < 3; i++) {
    cout << nums[order[i]-'A'] << " ";
  }

  return 0;
}
