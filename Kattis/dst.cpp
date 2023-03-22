#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        char c;
        int d, h, m;
        cin >> c >> d >> h >> m;

        if (c == 'F') {
            m += d;
            if (m > 59) {
                h = (h+(m/60))%24;
                m %= 60;
            }
        } else {
            m -= d;
            while (m < 0) {
                m += 60;
                h = (!h ? 23 : h-1);
            }
        }
        cout << h << " " << m << endl;
    }
    return 0;
}