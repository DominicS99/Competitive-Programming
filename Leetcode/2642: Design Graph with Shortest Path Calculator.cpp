typedef pair<int, int> pii;
class Graph {
public:
    vector<vector<pii>> al;

    Graph(int n, vector<vector<int>>& edges) {
        al.resize(n);
        for (auto &e : edges) {
            al[e[0]].emplace_back(e[1], e[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        al[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        int n = al.size();
        vector<int> dist(n, 1e9); dist[node1] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq; pq.emplace(dist[node1], node1);
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            
            for (auto &[v, w] : al[u]) {
                if (dist[v] <= dist[u] + w) continue;
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
        return dist[node2] == 1e9 ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */