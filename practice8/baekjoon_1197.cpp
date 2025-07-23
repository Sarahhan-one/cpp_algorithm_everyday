#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> p;
int find(int x) {
    if (p[x] < 0) return x;
    else return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;

    if (p[v] < p[u]) swap(u, v);
    if (p[v] == p[u]) p[u]--; 
    p[v] = u;
    return true;
}

int main() {
    int V, E;
    cin >> V >> E; 

    p.resize(V+1, -1);
    vector<tuple<int, int, int>> nodes; //cost, node1, node2
    for (int i = 0; i < E; i++) {
        int nodeOne, nodeTwo, cost; 
        cin >> nodeOne >> nodeTwo >> cost; 

        nodes.push_back({cost, nodeOne, nodeTwo});
    }

    sort(nodes.begin(), nodes.end());

    int ans = 0;
    for (int i = 0; i < E; i++) {
        auto [cost, nodeOne, nodeTwo] = nodes[i];
        if (!uni(nodeOne, nodeTwo)) continue;
        ans += cost;
    }
    cout << ans;
}