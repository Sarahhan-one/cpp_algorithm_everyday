#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std; 

int main() {
    int V, E, SP;
    cin >> V >> E >> SP;

    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v, w; 
        cin >> u >> v >> w; 

        adj[u-1].push_back({v-1, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, 20000 * 10);

    // initial value
    pq.push({0, SP-1}); // cost, u
    dist[SP-1] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; 
        pq.pop(); 

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second; 

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (auto d : dist) {
        if (d == 20000 * 10) cout << "INF" << '\n';
        else cout << d << '\n';
    }

}