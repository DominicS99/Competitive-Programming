#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    a += b;
    sort(a.begin(), a.end());
    cout << a << "\n";
    return 0;
}