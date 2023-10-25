/*
  Idea: Interesting greedy problem. The crucial idea is that the strongest animal
    is always safe, and the next strongest is safe as long as it defends the next
    x strongest animals where the defense >= attack. Therefore, this group of strongest
    animals will now try to remove every other animal, so the process repeats with a
    much stronger attacking group.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  
  int n; cin >> n;
  vector<int> d(n); for (auto &it : d) cin >> it;
  sort(d.rbegin(), d.rend());
  
  ll attack = d[0];
  int res = 1;
  for (int i = 1; i < n; ) {
    int defense = 0;
    while (i < n && attack > defense) defense += d[i++];
    if (attack > defense) break;

    res = i;
    attack += defense;
  }

  cout << res << "\n";
  return 0;
}

/*
// Initial Version
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<int> d(n);
  for (auto &it : d) cin >> it;
  sort(d.rbegin(), d.rend());
  
  ll attack = d[0], defense = 0;
  int res = 1, i = 1;
  while (i < n) {
    while (i < n && attack > defense) {
      defense += d[i];
      i++;
    }
    if (attack > defense) break;
    res = i;
    attack += defense;
    defense = 0;
  }

  cout << res << endl;
}
*/