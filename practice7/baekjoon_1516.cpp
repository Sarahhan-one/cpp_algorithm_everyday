#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N; 
    cin >> N;

    vector<vector<int>> adj(N+1);
    vector<int> degree(N+1);
    vector<int> costs(N+1, 0);
    vector<int> ans(N+1, 0);

    for (int i = 0; i < N; i++) {
        int n; 
        cin >> n;
        costs[i+1] = n;

        int m;
        do { 
            cin >> m; 
            if (m == -1) break;
            degree[i+1]++; 
            adj[m].push_back(i+1);
        }while (m != -1);
    }

    // for (int i = 1; i <= N; i++) {
    //     for (auto adjNode : adj[i]) {
    //         cout << adjNode << " ";
    //     }
    //     cout <<'\n';
    // }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // {cost, u}
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) q.push({costs[i], i});
    }

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        ans[u] = costs[u];

        for (int v : adj[u]) {
            degree[v]--;
            if (degree[v] == 0) {
                costs[v] += costs[u];
                q.push({costs[v], v});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}