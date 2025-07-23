#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std; 

int main() {
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    vector<int> dist(F+1, INT_MAX);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 

    pq.push({S, 0}); // u, cost 
    dist[S] = 0; 

    while (!pq.empty()) {
        int u = pq.top()[0];
        int cost = pq.top()[1];
        pq.pop();
        
        if (u == G) { //exit condition
            cout << cost;
            return 0;
        }

        int v;
        v = u + U; 
        if (v <= F) {
            if (dist[u]+cost < dist[v]) {
                dist[v] = dist[u]+cost;
                pq.push({v, cost + 1});
            }
        }

        v = u - D;
        if (v > 0) {
            if (dist[u]+cost < dist[v]) {
                dist[v] = dist[u]+cost; 
                pq.push({v, cost + 1});
            }
        }
    }

    cout << "use the stairs";
}