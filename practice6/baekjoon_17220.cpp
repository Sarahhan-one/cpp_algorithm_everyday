#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M; 
    cin >> N >> M;

    vector<int> degree(N);
    vector<vector<int>> adj(N, vector<int>());
    
    for (int i = 0; i < M; i++) {
        char source, receive; 
        cin >> source >> receive;
        adj[source - 'A'].push_back(receive - 'A');
        degree[receive - 'A']++;
    }

    int num; 
    cin >> num; 
    vector<int> arrested;
    char c;
    for (int i = 0; i < num; i++) {
        cin >> c;
        arrested.push_back(c - 'A');
    }

    queue<int> q;

    // prepare the initial node "souce" - don't consider if it is arrested
    for (int i = 0; i < N; i++) { 
        bool isArrested = false;
        for (auto& arrestedNode : arrested) {
            if (i == arrestedNode) {
                isArrested = true;
                break;
            }
        }
        
        if (!isArrested && degree[i] == 0) q.push(i);
    }

    // reduce the degree who has arrested source node
    for (int arrestedNode : arrested) {
        for (auto& node : adj[arrestedNode]) {
            degree[node]--;
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int currNode = q.front();
        q.pop();

        // now check if nodes are arrested
        for (auto& adjNode : adj[currNode]) {
            bool isArrested = false;
            for (auto& arrestedNode : arrested) {
                if (adjNode == arrestedNode) {
                    isArrested = true;
                    break;
                }
            }

            if (isArrested) continue; // if it's arrested, skip it

            degree[adjNode]--;

            if (degree[adjNode] == 0) {
                cnt++;
                q.push(adjNode);
            }
        }
    }
    cout << cnt;
}