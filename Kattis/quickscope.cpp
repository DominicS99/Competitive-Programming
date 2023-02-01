/*
  Idea is that each code block is stored within a hashmap, and you can access this hashmap from any level. (line 20)
  The keys are the variable names, and the values are the different datatypes, all stored within a stack which we manipulate.
  We use the stack 'curr' to know what var names are being used within this specific code block (stored within unordered_set), 
    as we are always on this "lowest" level. (line 21) This allows us to:
      - Know what names have been declared on this level in order to pop them from the hashmap's stack (line 44)
      - If the 'TYPEOF' is asked for, it will only check if it's been utilized within the hashmap, rather than the current level itself. (line 36)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  string act, name, type;
  int n;
  cin >> n;
  unordered_map<string, stack<string>> names;
  stack<unordered_set<string>> curr;
  curr.emplace();
  
  while (n--) {
    cin >> act;
    if (act[0] == 'D') {
      cin >> name >> type;
      if (curr.top().count(name)) {
        cout << "MULTIPLE DECLARATION" << endl;
        break;
      }
      names[name].push(type);
      curr.top().insert(name);
    } else if (act[0] == 'T') {
      cin >> name;
      if (!names[name].empty()) {
        cout << names[name].top() << endl;
      } else {
        cout << "UNDECLARED" << endl;
      }
    } else if (act[0] == '{') {
      curr.emplace();
    } else {
      for (auto it : curr.top()) names[it].pop();
      curr.pop();
    }
  }
  return 0;
}
