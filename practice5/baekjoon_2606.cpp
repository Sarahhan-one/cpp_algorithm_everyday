#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
    int M, N; 
    cin >> M;
    cin >> N; 

    vector<vector<int>> adj(M+1);
    queue<int> q;
    vector<bool> vis(M+1, false);
    vis[1] = true;

    for (int i = 0; i < N; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2; 
        adj[temp1].push_back(temp2); 
        adj[temp2].push_back(temp1);
    }

    for (auto& node : adj[1]) {
        q.push(node);
        vis[node] = true;
    }

    int ans = 0; 
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans++;

        // cout << node << " ";

        for (auto& node_node : adj[node]) {
            if (vis[node_node]) continue;
            vis[node_node] = true;
            q.push(node_node);
        }
    }

    cout << ans;
}