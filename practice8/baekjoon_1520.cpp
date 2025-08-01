#include <iostream>
#include <vector>
using namespace std;

int N, M; 
vector<vector<int>> grid;
vector<vector<int>> vis;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
    if (x == N-1 && y == M-1) {
        return 1; // 1 path found
    }

    if (vis[x][y] != -1) return vis[x][y];

    int totalPath = 0; //total path from this cell

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;//check boundary
        if (grid[nx][ny] >= grid[x][y]) continue;

        totalPath += dfs(nx, ny);
    }
    vis[x][y] = totalPath;
    return totalPath;
}

int main() {
    cin >> N >> M; 

    grid.resize(N, vector<int>(M));
    vis.assign(N, vector<int>(M, -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vis[i][j] == -1){
                dfs(i, j); 
            }
        }
    }

    cout << vis[0][0];
}