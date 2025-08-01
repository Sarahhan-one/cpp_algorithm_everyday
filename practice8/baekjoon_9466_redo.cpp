#include <iostream>
#include <vector>
using namespace std;

vector<int> adj;

void dfs(int start, vector<bool>& vis, int node) {
    if (vis[node]) return;
    vis[node] = true;

    
    int adjNode = adj[node];

    dfs(start, vis, adjNode);
    if (start != node)  vis[node] = false;
}

void print(vector<bool>& vis) {
    for (int i = 1; i < vis.size(); i++) {
        cout << vis[i] << " ";
    }
    cout << endl;
}

int main() {
    int M, N;
    cin >> M;
    while (M--) {
        cin >> N; 

        adj.resize(N+1);
        for (int i = 1; i <= N; i++) {
            cin >> adj[i];
        }

        vector<bool> vis(N+1, false);
        for (int i = 1; i <= N; i++) {
            print(vis);
            dfs(i, vis, i);
        }

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) ans++;
        }

        cout << ans << endl;
    }



}