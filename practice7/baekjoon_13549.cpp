#include <iostream> 
#include <vector>
#include <queue> 
using namespace std; 

#define MAX (100000)

int main() {
    int sp, dp; 
    cin >> sp >> dp;

    vector<int> dist(MAX+1, MAX);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    pq.push({0, sp}); //cost u
    dist[sp] = 0;

    while (!pq.empty()) {
        int cost = pq.top()[0]; 
        int u = pq.top()[1];
        pq.pop();

        if (u == dp) break;

        if(dist[u] != cost) continue;

        int v = u-1;
        if (v >= 0 && v <= MAX) {
            if (dist[u] + 1 < dist[v]) {
                pq.push({dist[u] + 1, v});
                dist[v] = dist[u] + 1;
            }
        }

        int v1 = u+1;
        if (v1 >= 0 && v1 <= MAX) {
            if (dist[u] + 1 < dist[v1]) {
                pq.push({dist[u] + 1, v1});
                dist[v1] = dist[u] + 1;
            }
        }

        int v2 = 2*u; 
        if (v2 >= 0 && v2 <= MAX) {
            if (dist[u] < dist[v2]) {
                pq.push({dist[u], v2});
                dist[v2] = dist[u];
            }
        }
    }
    cout << dist[dp];
}