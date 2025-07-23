#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N; 
    cin >> N; 

    vector<vector<int>> adj(N+1);
    vector<int> degree(N+1, 0);
    vector<int> costs(N+1);
    for (int i = 1; i <= N; i++) { //1-indexed
        int cost; 
        cin >> cost; 
        costs[i] = cost;

        int n; 
        cin >> n;

        while (n--) {
            int prevNode;
            cin >> prevNode;

            // cout << i << " : " << prevNode << '\n';
            degree[i]++;
            adj[prevNode].push_back(i);
        }        
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << degree[i] << '\n';
    // }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >>> pq; // {cost, u} - get the smaller one first
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) {
            pq.push({costs[i], i});
        }
    }

    int totalCost = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        // cout << u << " " << cost << '\n';
        totalCost = costs[u]; // take the last one

        for (int v : adj[u]) {
            degree[v]--;
            if (degree[v] == 0) {
                costs[v] += costs[u]; // saves the biggest cost among prevNode
                pq.push({costs[v], v});
            }
        }
    }

    cout << totalCost;
}