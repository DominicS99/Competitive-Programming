/*
    Simulate a stack using an array. For each query, you can "move the number" to the back by changing the index (m[x]) it's pointing to (nxt).

    The problem lies with updating a single point for each query, and needing to find a new answer query efficiently. That's where Fenwick Tree (aka BIT) comes in. 
    
    For this, I picture that for each index that's less than or equal to n, it starts off with a movie in its initial spot, and note this with a value 1.
        - Note that I also change the indexing from 1-N to 0-(N-1). Not neccessary, but it helps me index a bit easier

    For each query, you can take the range sum in O(log(n)) time using the boiler plate BIT struct.
    After each query, you need to update two points in O(log(n)): decrease the value of the position x was currently pointing to, and increase the value of the position x will be pointing to.

    Example: 
            3  2  1                                    3  2  1
    start: [1, 1, 1, 0, 0, 0]   -> range sum answers: [2, 1, 0, 0, 0, 0]

                              2  1  3                      2  1  3
    after queryMovie = 3: [0, 1, 1, 1, 0, 0]    -> rs: [3, 2, 1, 0, 0, 0]

                              2     3  1                   2     3  1
    after queryMovie = 1: [0, 1, 0, 1, 1, 0]    -> rs: [3, 2, 2, 1, 0, 0]

                              2     3     1                2     3     1
    after queryMovie = 1: [0, 1, 0, 1, 0, 1]    -> rs: [3, 2, 2, 1, 1, 0]

        - Note for range sum answers, you would only query on entries where an index points to it
*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct BIT {
    int n;
    vector<ll> tree;

    BIT(int size) {
        n = size+1;
        tree.resize(n);
    }

    void update(int i, ll diff) {
        for (i = i+1; i < n; i += (i & -i)) {
            tree[i] += diff;
        }
    }

    ll query(int i) {
        ll res = 0;
        for (i = i+1; i > 0; i -= (i & -i)) {
            res += tree[i];
        }
        return res;
    }

    ll rQuery(int l, int r) {
        return query(r) - query(l-1);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int _t; cin >> _t;
    while (_t--) {
        int n, q, x; cin >> n >> q;

        vector<int> m(n);
        BIT tree(n+q);
        for (int i = 0; i < n; i++) {
            tree.update(i, 1);
            m[n-i-1] = i;
        }

        int nxt = n;
        while (q--) {
            cin >> x; x--;
            cout << tree.rQuery(m[x]+1, nxt) << " ";

            tree.update(m[x], -1);
            m[x] = nxt++;
            tree.update(m[x], 1);
        }
        cout << "\n";
    }
    return 0;
}