#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
void dfs(vector<vector<int>>& nodes, vector<bool>& deleted, int deletedNode) {
    deleted[deletedNode] = true;
    
    for (int adjNode : nodes[deletedNode]) {
        dfs(nodes, deleted, adjNode);
    }
}

int main() {
    int N; 
    cin >> N; 

    vector<vector<int>> child(N);
    vector<int> mom(N);
    for (int i = 0; i < N; i++) {
        int node; 
        cin >> node;
        
        if (node == -1) continue;
        mom[i] = node;
        child[node].push_back(i);
    }


    int deletedNode; 
    cin >> deletedNode;

    vector<bool> deleted(N, false);
    dfs(child, deleted, deletedNode);

    int leafNodeCnt = 0;
    for (int i = 0; i < N; i++) {
        if (deleted[i]) continue;

        bool hasChild = false;
        for (int c : child[i]) {
            if (!deleted[c]) {
                hasChild = true;
                break;
            }
        }

        if (!hasChild) leafNodeCnt++;

    }

    cout << leafNodeCnt;
    return 0;
}