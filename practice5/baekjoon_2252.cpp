#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    //1-indexed 
    vector<vector<int>> adj(N+1);
    vector<int> degree(N+1, 0); 

    for (int i = 0; i < M; i++) {
        int node1, node2; 
        cin >> node1 >> node2;

        adj[node1].push_back(node2); 
        degree[node2]++;
    }

    queue<int> q; 
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) {
            q.push(i); 
        }
    }

    vector<int> res; 
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);

        for (auto& adj : adj[cur]) {
            degree[adj]--; 
            if (degree[adj] == 0) q.push(adj);
        }
    }

    for (auto& r : res) {
        cout << r << " ";
    }

}