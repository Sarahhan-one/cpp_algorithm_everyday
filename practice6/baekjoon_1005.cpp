#include <iostream>
#include <vector>
#include <queue> 
#include <limits.h>
using namespace std; 



int main() {
    int T, N, K, W; 

    cin >> T;
    while (T--) {
        int ans = 0; 
        cin >> N >> K; 

        vector<int> constructionTime(N+1);
        for (int i = 1; i <= N; i++) {
            cin >> constructionTime[i];
        }
        
        vector<int> degree(N+1, 0);
        vector<vector<int>> adj(N+1);
        for (int i = 0; i < K; i++) {
            int nodeOne, nodeTwo; 
            cin >> nodeOne >> nodeTwo; 
            adj[nodeOne].push_back(nodeTwo);
            degree[nodeTwo]++;
        }
        
        cin >> W;

        queue<int> q; 
        int nodeCnt = 0;
        for (int i = 1; i <= N; i++) {
            if (degree[i] == 0) { 
                q.push(i); nodeCnt++; 
            }
        }
        
        int maxTime = 0;
        while (!q.empty()) {
            int currNode = q.front();
            q.pop(); nodeCnt--; 
            
            if (currNode == W) {
                ans += constructionTime[currNode]; 
                break;
            }

            maxTime = max(maxTime, constructionTime[currNode]);

            for (int& adjNode : adj[currNode]) {
                degree[adjNode]--;
                if (degree[adjNode] == 0) { 
                    q.push(adjNode); nodeCnt++;
                }
            }  
            
            if (nodeCnt == 0) {
                ans += maxTime;
                maxTime = 0;
            }
        }
        cout << ans << '\n';
    }
}