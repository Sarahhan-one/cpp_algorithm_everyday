#include <iostream>
#include <vector> 
using namespace std;

vector<vector<pair<int, int>>> tree;
int maxDist = 0;
int fartestNode = 0;

void recursive(int node, int const node2, int dist) {
    if (maxDist < dist) {
        maxDist = dist;
        fartestNode = node;
    }

    for (auto [adjNode, weight] : tree[node]) {
        if (adjNode != node2) { //parent check
            recursive(adjNode, node, dist + weight);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;

    if (N == 1) {
        cout << 0; 
        return 0;
    }

    tree.resize(N+1);

    for (int i = 0; i < N; i++) {
        int mother, child, weight;
        cin >> mother >> child >> weight;

        tree[mother].push_back({child, weight});
        tree[child].push_back({mother, weight});
    }
    
    recursive(1, -1, 0); //find the fartest node from node 1
    
    maxDist = 0;
    recursive(fartestNode, -1, 0); // find the fartest node from the fartest node
    

    cout << maxDist;
}