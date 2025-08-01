#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int N, M, X; 
priority_queue<pair<int, int>> pq; //dist, u
vector<int> dist;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int i) {
    dist.assign(M+1, INT_MAX); //reset the dist array

    pq.push({0, i});
    dist[i] = 0;

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (dist[u] != cost && u == X) break;
        if (dist[u] != cost) continue; //u is already updated

        for (auto [v, d] : adj[u]) {
            if (dist[v] > dist[u] + d) {
                dist[v] = dist[u] + d;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> adj; //u | v, dist
    vector<vector<pair<int, int>>> reverse_adj; //u | v, dist

    adj.resize(M+1); 
    reverse_adj.resize(M+1);

    for (int i = 0; i < M; i++) {
        int v1, v2, d;
        cin >> v1 >> v2 >> d;

        adj[v1].push_back({v2, d}); //v, dist
        reverse_adj[v2].push_back({v1, d});
    }

    vector<int> distFromX = dijkstra(adj, X); 
    vector<int> distToX = dijkstra(reverse_adj, X);

    // for (int i = 1; i <= N; i++) { //for debugging
    //     cout << dist[i] << " ";
    // }
    // cout << endl;

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, distFromX[i] + distToX[i]);
    }
    cout << ans;
}