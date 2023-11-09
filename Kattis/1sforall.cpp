/**
 * @file 1sforall.cpp
 * @author Dominic Sagen
 * @brief For this problem, you have to find the minimum number of 1's to reach a number n.
 *   There are 2 ways I noticed to approach this problem:
 *      Dijkstra (Shortest Path): Found this more intuitive, so I coded it below. Apply all operations to a given number, use min PQ to maintain the best possible move. Ends when you reach the number you're looking for.
 *      Dynamic Programming: You can also build the best possible state for every number through 1D DP. This relies on you working backwards, building the table up from all combinations of addition, multiplication, and concatenation which lead to the current number you are at. Much faster solution than the shortest path code I made here.
 *   Note: Time Limit is 15 SECONDS! I was worried my solutions wouldn't work because they took longer than a second, but it's fine for this problem.
 * @version 0.1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int concatNum(int x, int y) {
    string a = to_string(x), b = to_string(y);
    a += b;
    return stoi(a);
}

int main() {
    int n, v; cin >> n;
    vector<int> dist(n+1, 1e9); 
    dist[0] = 0; dist[1] = 1;
    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.emplace(1, 1);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        if (u == n) break;

        for (int i = 1; i <= n; i++) {
            v = u+i;
            if (v > n) break;
            if (dist[v] <= dist[u] + dist[i]) continue;
            dist[v] = dist[u] + dist[i];
            pq.emplace(dist[v], v);
        }

        for (int i = 2; i <= n; i++) {
            v = u*i;
            if (v > n) break;
            if (dist[v] <= dist[u] + dist[i]) continue;
            dist[v] = dist[u] + dist[i];
            pq.emplace(dist[v], v);
        }

        for (int i = 1; i <= n; i++) {
            v = concatNum(u, i);
            if (v > n) break;
            if (dist[v] <= dist[u] + dist[i]) continue;
            dist[v] = dist[u] + dist[i];
            pq.emplace(dist[v], v);
        }
    }

    cout << dist[n] << "\n";

    return 0;
}