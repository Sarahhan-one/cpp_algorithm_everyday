#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> adj;
vector<int> vis;
vector<int> cycles;

void dfs(int node) {
    if (vis[node] == 2) return; //already processed

    if (vis[node] == 1) { //found a loop
        int start = node;
        cycles[start] = 2;

        int adjNode = adj[node];
        
        while (adjNode != start) {
            cycles[adjNode] = 2;
            adjNode = adj[adjNode];
        }
        return;
    }

    vis[node] = 1; // it is now processing

    int adjNode = adj[node];
    if (adjNode == node) { //self-loop
        cycles[node] = 1;
        vis[node] = 2;
    }
    else {
        dfs(adjNode);

        vis[node] = 2;
    }
}

int main() {
    int M, N;
    cin >> M;
    while (M--) {
        cin >> N; 

        adj.assign(N+1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> adj[i];
        }

        vis.assign(N+1, 0); // 0: unvisited, 1: in path, 2: processed
        cycles.assign(N+1 , 0); // 0: not part of a loop, 1: self-loop, 2: part of a
        for (int i = 1; i <= N; i++) {
            if (vis[i] == 0) {
                dfs(i);
            }
        }

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (cycles[i] == 0) ans++;
            // cout << cycles[i] << endl;
        }
        cout << ans << endl;
        // cout << endl;
    }
}