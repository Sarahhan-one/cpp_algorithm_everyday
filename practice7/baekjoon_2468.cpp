#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N; 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int h) {
    queue<pair<int, int>> q;
    q.push({i, j}); 
    vis[i][j] = true;

    while (!q.empty()) {
        int x = q.front().first; 
        int y = q.front().second;
        q.pop(); 

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (vis[nx][ny]) continue;

            if (grid[nx][ny] > h) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
    return;
}

int main() {
    cin >> N; 

    vector<vector<int>> grid(N, vector<int>(N));
    int max_height = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            max_height = max(grid[i][j], max_height);
        }
    }


    vector<vector<bool>> vis(N, vector<bool>(N, false));
    int ans = 0;
    int cnt;
    for (int h = 0; h < max_height; h++) { //for different precipitation
        cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!vis[i][j] && grid[i][j] > h) {
                    cnt++;
                    bfs(grid, vis, i, j, h);
                }
            }
        }
        ans = max(ans, cnt);
        fill(vis.begin(), vis.end(), vector<bool>(N, false));
    }

    cout << ans;
} 