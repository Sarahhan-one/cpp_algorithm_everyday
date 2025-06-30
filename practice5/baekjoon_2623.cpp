#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

int main() {
    int N, M; 
    cin >> N >> M; 

    vector<vector<int>> adj(N+1); 
    vector<int> degree(N+1, 0);
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num; 

        int temp1, temp2; 
        cin >> temp1;
        for (int j = 0; j < num-1; j++) {
            cin >> temp2;
            adj[temp1].push_back(temp2);
            degree[temp2]++;

            temp1 = temp2;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) q.push(i);
    }

    vector<int> res;
    while (!q.empty()) {
        int curr = q.front();
        q.pop(); 
        res.push_back(curr);

        for (auto& adj : adj[curr]) {
            degree[adj]--;
            if (degree[adj] == 0) q.push(adj);
        }
    }

    if (res.size() != N) cout << 0; 
    else {
        for (auto& r : res) {
            cout << r << "\n";
        }
    }
}