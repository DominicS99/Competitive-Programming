/*
Note: 
  Test Case 11 produces integer overflow with this DSU solution.
  If you are doing everything else right and not getting TLE, then change these 3 to ll (long long int):
    Change return type of journeyToMoon function (line 60)
    Change data type of res (line 64)
    Most importantly: Change data type of result in the main function (line 101)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

class DSU {
public:
    vector<int> parent;
    vector<int> size;

  DSU(int n) {
    parent.resize(n, -1);
    size.resize(n, 1);
  }
  
  int find_set(int v) {
    if (parent[v] == -1) {
      parent[v] = v;
      return v;
    }
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
  }
  
  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a,b);
      parent[b] = a;
      size[a] += size[b];
      size[b] = -1;
    }
  }
};


/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

ll journeyToMoon(int n, vector<vector<int>> astronaut) {
    DSU d(n);
    for (auto &a : astronaut) d.union_sets(a[0], a[1]);
    
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += (n - d.size[d.find_set(i)]);
    }
    return res/2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    ll result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
