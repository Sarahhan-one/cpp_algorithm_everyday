#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int N;
int ans = INT_MAX; 


void dfs(int x, vector<vector<int>>& grid, int cnt, vector<bool>& vis, int depth) {
    if (depth == N-1) { // base case: if we have processed all rows and we return to the first row
        if (grid[x][0] > 0) {
            ans = min(ans, cnt + grid[x][0]);
        }
        // cout << "Current sum: " << cnt << endl; 
        return;
    }

    if (cnt >= ans) return; 
    for (int y = 0; y < N; y++) { // iterate through columns
        if (vis[y] || grid[x][y] == 0) continue;
        vis[y] = true; // mark as visited
        dfs(y, grid, cnt + grid[x][y], vis, depth+1); //go to the row via column i 
        vis[y] = false; // unmark for backtracking
    }
}

int main() {
    cin >> N; 
    
    vector<vector<int>> grid(N, vector<int> (N, 0));
    vector<bool> vis(N, false);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    //pick the num from each row
    //move from row to row via columns 
    //minimize the sum of the numbers picked
    vis[0] = true; // start from the first row
    dfs(0, grid, 0, vis, 0);

    cout << ans << endl;
}