/*
  Idea: Change the Calculator format from infix -> postfix, conduct operations as you go along.
  Negation vs minus, multiple digits, symbol priority. Time-consuming to work out the logic, but fun!
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  string s;
  unordered_map<char, int> prec;
  prec['+'] = 1;
  prec['-'] = 1;
  prec['*'] = 2;
  prec['/'] = 2;
  prec['n'] = 3;
  prec['('] = 0;
  
  while (getline(cin, s)) {
    stack<char> operators;
    stack<double> vals;

    function <void ()> performOperation = [&] {
      char op = operators.top();
      operators.pop();
      if (op == '(') return;
      
      double b = vals.top();
      vals.pop();
      
      if (op == 'n') {
        vals.push(b * -1.0);
        return;
      }
    
      double a = vals.top();
      vals.pop();
      if (op == '+') {
        vals.push(a+b);
      } else if (op == '-') {
        vals.push(a-b);
      } else if (op == '*') {
        vals.push(a*b);
      } else {
        vals.push(a/b);
      }
    };

    string temp = "";
    for (char c : s) {
      if (c == ' ') continue;
      
      if (c >= '0' && c <= '9') {
        temp += c;
        continue;
      }

      if (!temp.empty() && temp != "buffer") {
        vals.push(stoi(temp));
      }
      
      if (c == ')') {
        while (operators.top() != '(') {
          performOperation();
        }
        operators.pop();
        temp = "buffer";
        continue;
      } else if (c == '(') {
        operators.push(c);
      } else if (c == '-' && temp.empty()) {
        operators.push('n');
      }
      else {
        while (!operators.empty() && prec[operators.top()] >= prec[c]) {
          performOperation();
        }
        operators.push(c);
      }

      temp.clear();
    }

    if (!temp.empty() && temp != "buffer") {
      vals.push(stoi(temp));
    }
    
    while (!operators.empty()) performOperation();

    printf("%.2f\n", vals.top());
    
  }

  return 0;
}
