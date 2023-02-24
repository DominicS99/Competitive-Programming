#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  unordered_map<char, char> leet;
  leet['0'] = 'O';
  leet['1'] = 'L';
  leet['3'] = 'E';
  leet['5'] = 'S';
  leet['6'] = 'B';
  leet['7'] = 'T';
  leet['8'] = 'B';
  int n, m;
  string word;
  cin >> n >> m;
  unordered_set<string> bad;
  while (n--) {
    cin >> word;
    bad.insert(word);
  }

  vector<string> res;

  while (m--) {
    cin >> word;
    for (int i = 0; i < word.length(); i++) {
      if (leet.count(word[i])) {
        word[i] = leet[word[i]];
      }
    }

    bool f = false;
    for (auto &s : bad) {
      int end = word.length()-s.length();
      for (int i = 0; i < end; i++) {
        if (s == word.substr(i, s.length())) f = true;
      }
    }

    f ? res.push_back("INVALID") : res.push_back("VALID");
  }

  for (auto &it : res) {
    cout << it << endl;
  }
  
  return 0;
}
