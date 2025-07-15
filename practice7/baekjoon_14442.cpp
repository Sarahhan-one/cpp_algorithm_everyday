#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;

struct movement {
    int x;
    int y;
    int move;
    int wall_broken;
};

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool boundaryCheck(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M) return false;
    return true;
}

int bfs(vector<vector<int>>& grid) {
    queue<movement> movements;
    movements.push({0, 0, 1, 0}); //x, y, move, wall broken?

    vector<vector<vector<bool>>> vis(N, vector<vector<bool>>(M, vector<bool>(K+1, false)));
    vis[0][0][0] = true; // mark as visited

    while (!movements.empty()) {
        movement curr = movements.front();
        movements.pop();

        if (curr.x == N-1 && curr.y == M-1) { //exit condition
            return curr.move;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (!boundaryCheck(nx, ny)) continue;
            
            if (grid[nx][ny] == 0) {
                if (vis[nx][ny][curr.wall_broken]) continue;
                vis[nx][ny][curr.wall_broken] = true; // mark as visited
                movements.push({nx, ny, curr.move + 1, curr.wall_broken});
            }
            else if (grid[nx][ny] == 1 && curr.wall_broken < K) {
                if (vis[nx][ny][curr.wall_broken+1]) continue;
                vis[nx][ny][curr.wall_broken + 1] = true;
                movements.push({nx, ny, curr.move + 1, curr.wall_broken + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> K;

    vector<vector<int>> grid(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            grid[i][j] = (line[j] - '0');
        }
    }

    int ans = bfs(grid);
    cout << ans;
    return 0;
}