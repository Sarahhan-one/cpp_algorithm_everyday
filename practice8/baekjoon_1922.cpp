#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> p;

int find(int x) {
    if (p[x] < 0) return x; 
    return p[x] = find(p[x]);
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
    int N, M; 
    cin >> N >> M;

    vector<tuple<int, int, int>> nodes; //node1, node2, cost
    for (int i = 0; i < M; i++) {
        int nodeOne, nodeTwo, cost;
        cin >> nodeOne >> nodeTwo >> cost;
        nodes.push_back({cost, nodeOne, nodeTwo});
    }

    sort(nodes.begin(), nodes.end());
    // for (auto [cost, nodeOne, nodeTwo] : nodes) {
    //     cout << cost << " " << nodeOne << " " << nodeTwo << '\n';
    // }

    p.resize(N+1, -1);

    int ans = 0;
    for (int i = 0; i < M; i++) {
        auto [cost, nodeOne, nodeTwo] = nodes[i];
        if (!uni(nodeOne, nodeTwo)) continue;

        ans += cost;
        // cout << ans << '\n';
    }
    cout << ans;

}