#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

void convertLine(string &s, vector<string> &res) {
  string val;
  stringstream ss(s);
  while (getline(ss, val, ' ')) res.push_back(val);
}

int main() {
    int n, i = 1;
    while (cin >> n) {
        if (n == 0) break;
        cin.ignore();
        map<string, int> m;
        while (n--) {
            string line, animal;
            getline(cin, line);
            vector<string> row;
            convertLine(line, row);

            animal = row.back();
            transform(animal.begin(), animal.end(), animal.begin(), [&](auto &c) {
                return tolower(c);
            });
            m[animal]++;
        }
        cout << "List " << i++ << ":\n";
        for (auto &[s, v] : m) {
            cout << s << " | " << v << "\n";
        }
    }

    return 0;
}