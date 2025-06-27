#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;

//dfs - look for adjacent nodes
//if the depth is 5, return 1
//if we explore all the pairs, exit

bool dfs(int curr, vector<vector<int>>& list, int depth, vector<bool>& vis) {
    if (depth == 5) return true; //exit condition

    for (int adj : list[curr]) {
        if (!vis[adj]) {
            vis[curr] = true;
            if (dfs(adj, list, depth + 1, vis)) return true; 
            vis[curr] = false; //try with different order
        }
    }
    return false;
}

int main() {
    int N, M;
    cin >> N >> M; 

    vector<vector<int>> list(N);
    vector<bool> vis(N, false);
    for (int i = 0; i < M; i++) {
        int temp1, temp2; 
        cin >> temp1 >> temp2; 
        list[temp1].push_back(temp2); //if A-B is friend, B-A is also friend
        list[temp2].push_back(temp1);
    }

    for (int i = 0; i < N; i++) { //check everyone
        fill(vis.begin(), vis.end(), false);
        vis[i] = true;

        if (dfs(i, list, 1, vis)) { //if there's one matches the condition, return 1
            cout << 1; 
            return 0;
        }
    }
    cout << 0; //else return 0
}