#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1); // u | v1 v2.. 
    vector<int> dist(N+1); // 1 | dist to Vs 
    while (M--){
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    int A; 
    cin >> A; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while (A--) {
        int v1, v2; 
        cin >> v1 >> v2; 
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);

        dist.assign(N+1, INT_MAX);

        pq.push({0, 1}); //dist, 1(capital)
        dist[1] = 0;

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (dist[u] != cost) continue;

            for (auto v : adj[u]) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    pq.push({dist[v], v});
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            if (dist[i] == INT_MAX) cout << -1 << ' ';
            else cout << dist[i] << ' ';
        }
        cout << endl;
    }
}