#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> nodes;

void dfs(int node, vector<bool>& vis, int& totalWeight, int& maxWeight) {
    if (nodes[node].empty()) return; //if the next node isCD "null", go back

    for (auto& adj : nodes[node]) {
        int adjNode = adj.first;
        int weight = adj.second;

        if (vis[adjNode]) continue;

        vis[adjNode] = true;
        totalWeight += weight;
        maxWeight = max(maxWeight, totalWeight); // keep the max traveling cost while exploring the adj nodes

        dfs(adjNode, vis, totalWeight, maxWeight); 

        vis[adjNode] = false;
        totalWeight -= weight;
    }

}

int main() {
    nodes.resize(10000);
    int idx, adjNode, weight; 
    while (cin >> idx >> adjNode >> weight) {
        nodes[idx].push_back({adjNode, weight});
        nodes[adjNode].push_back({idx, weight});
    }
    
    int ans = 0;
    for (int i = 1; i < nodes.size(); i++) { // setting different starting nodes
        //reset the values
        vector<bool> vis(nodes.size(), false);
        int totalWeight = 0, maxWeight = 0;
        vis[i] = true;

        dfs(i, vis, totalWeight, maxWeight);
        ans = max(ans, maxWeight);
    }

    cout << ans;
}