#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> d(n);
  for (auto &it : d) cin >> it;

  string letters = "abcdefghijklmnopqrstuvwxyz";
  set<char> lettersUsed;
  unordered_map<char, string> m;
  for (char c : letters) {
    m[c] = letters;
  }
  for (string &s : d) {
    for (int i = 0; i < 3; i++) {
      char c = s[i];
      lettersUsed.insert(c);
      for (int j = 0; j < 3; j++) {
        if (i == j) continue;
        if (c == s[j]) {
          cout << "0" << endl;
          return 0;
        }

        int temp = m[c].find(s[j]);
        if (temp != string::npos) m[c].erase(temp, 1);
      }
    }
  }

  if (lettersUsed.size() > 18) {
    cout << "0" << endl;
    return 0;
  }

  // for (auto &it : m) {
  //   cout << it.first << ": " << it.second << endl;
  // }

  vector<string> dice(3, "");
  for (char c : lettersUsed) {
    for (int i = 0; i < 3; i++) {
      if (dice[i].find(c))
    }
  }

  // Fill in rest
  // for (auto &it : dice) cout << it << endl;
  
  return 0;
}

/*
abc
aef
ade
*/

/*
abc
aef
acf
a b c       a b c
  e f         f e
*/

/*
vnfsg   wace tor

a f t
c o g
i k r
y e s
w u n
*/

/*
aft
afr
agr
aiv
atu
cgo
eku
esy
ikr
ikt
now

a f t
k g r
o i v
s u e
  y c
  w n

a: f g i r t u v
c: g o
e: k s u y
f: a t r
g: a c o r
i: a k r t v
k: i r t
n: o w
o: c g n w
r: a f g i k
s: e y
t: a f i k u
u: a e k t
v: a i
w: n o
y: e s


a f t
  g r
  u

k i v
    e

s y
c   o
n w


a f t
  g r 
  u


c   o
*/
