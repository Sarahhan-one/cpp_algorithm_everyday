#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

int main() {
    int N, M; //col, row
    cin >> N >> M;

    vector<vector<char>> grid(M, vector<char>(N));
    queue<pair<int, int>> laserPos;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'C') {
                laserPos.push({i, j});
            }   
        }
    }

    vector<vector<vector<bool>>> vis(M, vector<vector<bool>>(N, vector<bool>(4, false)));
    
    queue<vector<int>> q; 

    auto sp = laserPos.front();
    laserPos.pop();

    for (int i = 0; i < 4; i++) { //put different direction points
        q.push({sp.first, sp.second, i, 0}); // x, y, dir, cnt
        vis[sp.first][sp.second][i] = true;
    }
    
    auto dp = laserPos.front();

    int dx[4] = {0, 0, 1, -1}; // E, W, S, N
    int dy[4] = {1, -1, 0, 0};

    while (!q.empty()) {
        int x = q.front()[0]; 
        int y = q.front()[1];
        int dir = q.front()[2];
        int cnt = q.front()[3];
        q.pop();

        if (x == dp.first && y == dp.second) {
            cout << cnt; 
            return 0;
        }

        int i = 1;
        while (true) {
            int nx = x + dx[dir]*i;
            int ny = y + dy[dir]*i;

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) break;
            if (grid[nx][ny] == '*') break;
            if (vis[nx][ny][dir]) break;

            vis[nx][ny][dir] = true;
            q.push({nx, ny, dir, cnt});
            i++;
        }

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