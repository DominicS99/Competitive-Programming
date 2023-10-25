#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string a = (n > m ? "needs " : "will have ");
    int b = abs(n-m);
    string c = (n > m ? " more" : "");
    string d = (b == 1 ? " piece" : " pieces");
    string e = (n > m ? "" : " left over");

    cout << "Dr. Chaz " << a << b << c << d << " of chicken" << e << "!\n";
    return 0;
}