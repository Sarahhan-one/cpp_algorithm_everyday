#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int M, N;   
    cin >> M >> N;

    vector<vector<int>> grid(M, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    int startX, startY, startDir;
    cin >> startX >> startY >> startDir;
    int destX, destY, destDir; 
    cin >> destX >> destY >> destDir; 

    queue<vector<int>> q; //x, y, dir, cnt
    vector<vector<vector<bool>>> vis(M, vector<vector<bool>>(N, vector<bool>(4, false)));

    // 0-indexed
    q.push({startX-1, startY-1, startDir-1, 0});
    vis[startX-1][startY-1][startDir-1] = true;

    int dx[4] = {0, 0, 1, -1}; //E, W, S, N
    int dy[4] = {1, -1, 0, 0};

    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int dir = q.front()[2];
        int cnt = q.front()[3]; 
        q.pop(); 

        // cout << x << " " << y << " " << dir << " " << cnt << endl;

        //exit condition
        if (x == destX-1 && y == destY-1 && dir == destDir-1) {
            cout << cnt;
            return 0;
        }

        //go k command
        for (int i = 1; i <= 3; i++) {
            int nx = x + dx[dir]*i;
            int ny = y + dy[dir]*i;

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) break;
            if (grid[nx][ny] == 1) break;
            if (vis[nx][ny][dir]) continue;

            if (grid[nx][ny] == 0) {
                q.push({nx, ny, dir, cnt+1});
                vis[nx][ny][dir] = true;
            }
        }

        //turn dir command
        if (dir == 0 || dir == 1) {
            if (!vis[x][y][2]) { q.push({x, y, 2, cnt+1}); vis[x][y][2] = true; }
            if (!vis[x][y][3]) { q.push({x, y, 3, cnt+1}); vis[x][y][3] = true; }
        }
        else if (dir == 2 || dir == 3) {
            if (!vis[x][y][0]) { q.push({x, y, 0, cnt+1}); vis[x][y][0] = true; }
            if (!vis[x][y][1]) { q.push({x, y, 1, cnt+1}); vis[x][y][1] = true; }
        }
    }

}