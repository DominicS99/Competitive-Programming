/*
  Idea: Postfix calculation, starting to enjoy this kind of problem!
  Be careful with integer vs double...
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n;
  vector<double> d(n);
  for (auto &it : d) cin >> it;
  cin >> s;

  stack<char> operators;
  stack<double> vals;

  function <void()> performOperation = [&] {
    char op = operators.top();
    operators.pop();
    if (op == '(') return;

    double b = vals.top();
    vals.pop();
    double a = vals.top();
    vals.pop();

    if (op == '-') {
      vals.push(a+b);
    } else {
      vals.push(1.0/(1.0/a + 1.0/b));
    }
  };

  for (char c : s) {
    if (c == 'R') continue;
    
    if (c >= '0' && c <= '9') {
      vals.push(d[c-'1']);
    } else if (c == ')') {
      while (operators.top() != '(') {
        performOperation();
      }
      operators.pop();
    } else {
      operators.push(c);
    }
  }

  while (!operators.empty()) performOperation();

  if (vals.empty()) vals.push(0);
  
  printf("%.5f\n", vals.top());
  return 0;
}
