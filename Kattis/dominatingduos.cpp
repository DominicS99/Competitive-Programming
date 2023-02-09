/*
  Solved this problem about half a year ago, didn't know about monotonic stack at that time.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int numOfPeople, personNum;
  stack<int> people;

  int i;

  cin >> numOfPeople;
  int count = numOfPeople-1;
  
  cin >> personNum;
  people.push(personNum);

  for (i = 1; i < numOfPeople; i++) {
    cin >> personNum;
    while (people.size() > 1 && personNum > people.top()) {
      people.pop();
      count++;
    }

    if (personNum > people.top()) {
      people.pop();
    }
    
    people.push(personNum);
  }

  cout << count;
}
