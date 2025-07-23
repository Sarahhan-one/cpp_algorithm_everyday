#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std; 

int main() {
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    vector<int> dist(F+1, INT_MAX);
    deque<int> dq; 

    dq.push_back(S); 
    dist[S] = 0; 

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        
        if (u == G) { //exit condition
            cout << dist[G];
            return 0;
        }

        int v;
        v = u + U; 
        if (v <= F) {
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u]+1;
                dq.push_back(v);
            }
        }

        v = u - D;
        if (v > 0) {
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u]+1;
                dq.push_back(v);
            }
        }
    }

    cout << "use the stairs";
}