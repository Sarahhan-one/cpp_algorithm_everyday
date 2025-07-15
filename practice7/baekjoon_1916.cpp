#include <iostream> 
#include <vector>
#include <queue> 
using namespace std;

#define MAX (100000 * 1000)

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N+1); // u | {v, cost}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> dist(N+1, MAX);
    
    for (int i = 0; i < M; i++) {
        int s, d, cost;
        cin >> s >> d >> cost; 

        adj[s].push_back({d, cost}); 
    }

    int SP, DP;
    cin >> SP >> DP;

    //initial setup 
    pq.push({0, SP}); //cost, u
    dist[SP] = 0;

    while(!pq.empty()) {
        int u = pq.top()[1];
        int cost = pq.top()[0];
        pq.pop();

        if (dist[u] != cost) continue;

        for (auto& x : adj[u]) {
            int v = x.first; 
            int weight = x.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[DP];
}