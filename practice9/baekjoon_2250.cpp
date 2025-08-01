#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> tree;
vector<vector<int>> width;
int cnt = 1;

vector<bool> vis;

void traversal(int node, int level) {
    if (node == -1) return;

    int leftNode = tree[node].first;
    int rightNode = tree[node].second;
    traversal(leftNode, level+1);
    width[level].push_back(cnt++);
    traversal(rightNode, level+1);
}

int main() {
    int N;
    cin >> N; 

    tree.resize(N+1); //left, right // -1 for no child node
    width.assign(N+1, {}); //max can be N+1
    
    vector<bool> rootFinding(N+1, true);
    for (int i = 0; i < N; i++) {
        int node, leftNode, rightNode; 
        cin >> node >> leftNode >> rightNode;

        tree[node] = {leftNode, rightNode};
        rootFinding[leftNode] = false;
        rootFinding[rightNode] = false;
    }

    int rootNode = -1;
    for (int i = 1; i <= N; i++) {
        if (rootFinding[i]) {
            rootNode = i;
            break;
        }
    }

    traversal(rootNode, 1);

    int ans = 0;
    int ans_level = 0;
    for (int i = N; i > 0; i--) {
        auto level = width[i];

        if (level.size() < 1) continue;

        int first = level[0]; 
        int last = level[level.size()-1];

        // cout << first << last << endl;

        ans = max(ans, last - first +1);
        if (ans == last - first +1) ans_level = i;
    }
    cout << ans_level << endl;
    cout << ans << endl;
}