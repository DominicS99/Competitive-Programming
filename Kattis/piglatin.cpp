#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    string line, vowels = "aeiouy";
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<string> words;
        for (string w; ss >> w;) words.push_back(w);
      
        for (auto &w : words) {
            auto j = w.find_first_of(vowels);
            w = (!j ? (w + "yay") : w.substr(j) + w.substr(0, j) + "ay");
        }
      
        for (auto &w : words) cout << w << " ";
        cout << endl;
    }

    return 0;
}


// #include <iostream>
// #include <sstream>
// #include <vector>
// using namespace std;

// template <class T> ostream& operator<<(ostream& os, const vector<T>& v) {
//     bool isFirst = 1;
//     for (auto &it : v) {
//         if (!isFirst) os << " ";
//         os << it;
//         isFirst = 0;
//     }
//     return os;
// };

// inline vector<string> split(const string& s) {
//     stringstream ss(s);
//     vector<string> res;
//     for (string w; ss >> w;) res.push_back(w);
//     return res;
// }

// int main() {
//     ios::sync_with_stdio(0); cin.tie(NULL);

//     string s, vowels = "aeiouy";
//     while (getline(cin, s)) {
//         vector<string> curr = split(s);
//         for (int i = 0; i < curr.size(); i++) {
//             auto j = curr[i].find_first_of(vowels);
//             curr[i] = (!j ? (curr[i] + "yay") : curr[i].substr(j) + curr[i].substr(0, j) + "ay");
//         }
//         cout << curr << endl;
//     }

//     return 0;
// }
