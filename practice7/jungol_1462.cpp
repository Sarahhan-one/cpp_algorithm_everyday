#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int L, W;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(vector<vector<char>>& grid, int i, int j, int ans)  {
    queue<vector<int>> q; //x, y, dist
    vector<vector<bool>> vis(L, vector<bool> (W, false));

    q.push({i, j, 0});
    vis[i][j] = true; 

    while (!q.empty()) {
        auto temp = q.front();
        int x =temp[0];
        int y = temp[1];
        int dist = temp[2];
        q.pop();

        for (int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= L || ny >= W) continue;
            if (vis[nx][ny]) continue; 

            if (grid[nx][ny] == 'L') {
                vis[nx][ny] = true;
                q.push({nx, ny, dist + 1});
            }
        }
        ans = max(ans, dist);
    }
    return ans;
}

int main() {
    cin >> L >> W; 

    vector<vector<char>> grid(L, vector<char>(W));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'L') {
                ans = max(ans, bfs(grid, i, j, ans));
            } 
        }
    }    
    cout << ans;
}