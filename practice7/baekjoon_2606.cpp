#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

int main() { 
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1);
    vector<bool> vis(N+1, false);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q; 
    q.push(1);
    vis[1] = true;

    int cnt = -1;
    while (!q.empty()) {
        cnt++; 
        int u = q.front(); 
        q.pop(); 

        for (auto& v : adj[u]) {
            if (vis[v]) continue;
            q.push(v);
            vis[v] = true;
        }
    }

    if (cnt == -1) cout << 0; 
    else cout << cnt;
    
}