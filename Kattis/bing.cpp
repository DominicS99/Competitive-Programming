// DP variation

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n;
  string word;
  cin >> n;
  unordered_map<string, int> m;

  while (n--) {
    cin >> word;
    cout << m[word] << endl;
    for (int i = 0; i < word.length(); i++) {
      m[word.substr(0, i+1)]++;
    }
  }

  return 0;
}
