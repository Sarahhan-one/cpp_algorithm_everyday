#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
int ans = INT_MAX;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool boundaryCheck(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M) return false;
    return true;
}

int bfs(vector<vector<int>>& grid) {
    queue<vector<int>> movements;
    movements.push({0, 0, 1, 0}); //x, y, move, wall broken?

    vector<vector<vector<bool>>> vis(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    vis[0][0][0] = true; // mark as visited

    while (!movements.empty()) {
        auto temp = movements.front();
        int x = temp[0], y = temp[1];
        int move = temp[2];
        int wall_broken = temp[3];
        movements.pop();

        if (x == N-1 && y == M-1) { //exit condition
            return move;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!boundaryCheck(nx, ny)) continue;
            if (vis[nx][ny][wall_broken]) continue;

            if (grid[nx][ny] == 0) {
                vis[nx][ny][wall_broken] = true; // mark as visited
                movements.push({nx, ny, move + 1, wall_broken});
            }
            else if (grid[nx][ny] == 1 && wall_broken == 0) {
                vis[nx][ny][1] = true;
                movements.push({nx, ny, move + 1, 1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            grid[i][j] = (line[j] - '0');
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << grid[i][j];
    //     }
    //     cout << '\n';
    // }

    int ans = bfs(grid);
    cout << ans;
    return 0;
}