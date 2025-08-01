#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_set>
using namespace std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;

    vector<unordered_set<int>> adj(N+M+1);

    for (int i = 0; i < M; i++) {
        int tube = N+1+i;
        for (int j = 0; j < K; j++) {
            int v;
            cin >> v;

            adj[v].insert(tube); //cost 0
            adj[tube].insert(v); //cost 1
        }
    }

    vector<int> dist(N+M+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({1, 1}); //cost, station 1 
    dist[1] = 1;

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (cost != dist[u] && u == N) break;
        if (cost != dist[u]) continue;

        for (auto v : adj[u]) {
            int new_cost;
            if (u <= N && v > N) { //station to auxiliary node -> no cost
                new_cost = 0;
            }
            else { //auxilary node to station -> cost 1
                new_cost = 1;
            }
            if (dist[v] > dist[u] + new_cost) {
                dist[v] = dist[u] + new_cost;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[N] == INT_MAX) cout << -1;
    else cout << dist[N];

}