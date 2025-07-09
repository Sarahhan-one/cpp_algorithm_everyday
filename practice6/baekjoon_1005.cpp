#include <iostream>
#include <vector>
#include <queue> 
using namespace std; 

int ans = 0; 
int N, K, W; 
vector<int> constructionTime(N+1);

void findMin(queue<int> q) {//pass the copy
    int temp = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        temp = min(temp, constructionTime[node]);
        cout << temp << ' ';
    }
    ans += temp;
}


int main() {
    cin >> N >> K; 

    for (int i = 1; i <= N; i++) {
        cin >> constructionTime[i];
    }
    cin >> W;
    
    vector<int> degree(N+1, 0);
    vector<vector<int>> adj(N+1);
    for (int i = 0; i < K; i++) {
        int nodeOne, nodeTwo; 
        cin >> nodeOne >> nodeTwo; 
        adj[nodeOne].push_back(nodeTwo);
        degree[nodeTwo]++;
    }

    queue<int> q; 
    int nodeCnt = 0;
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) { q.push(i); nodeCnt++; }
    }
    
    while (!q.empty()) {
        if (--nodeCnt == 0) findMin(q);

        int currNode = q.front();
        q.pop();

        for (int& adjNode : adj[currNode]) {
            degree[adjNode]--;
            if (degree[adjNode] == 0) { q.push(adjNode); nodeCnt++; }
        }  
    }

    cout << ans;
}