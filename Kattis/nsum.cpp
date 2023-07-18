#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    
    int result = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        result += x;
    }
    
    cout << result << endl;
    return 0;
}
