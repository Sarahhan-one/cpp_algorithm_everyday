#include <iostream>
#include <vector> 
#include <queue> 
using namespace std;

int N;

void printGrid(const vector<vector<int>>& grid) {
    for (int i = 0; i < N+2; i++) {
        for (int j = 0; j < N+2; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(vector<vector<int>>& vis, vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    
    for (int i = 0; i < N+2; i++) { //start from the edges
        q.push({i,0});
        q.push({i, N+1}); 
        q.push({0, i});
        q.push({N+1, i});

        vis[i][0] = 0;       
        vis[i][N+1] = 0; 
        vis[0][i] = 0;
        vis[N+1][i] = 0;
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; 
            int ny = y + dy[i];

            if (min(nx, ny) < 0 || max(nx, ny) >= N+2) continue; // boundary check

            int slope; 
            if (grid[nx][ny] - grid[x][y] == 0) slope = 0;
            else if (grid[nx][ny] - grid[x][y] > 0) slope = 1;
            else slope = -1;

            int diff = abs(grid[nx][ny] - grid[x][y]);
            int dist = (slope == 0) ? 0 : (slope == 1) ? diff*diff : diff; 

            if (vis[nx][ny] <= vis[x][y] + dist) continue; // pruning
            vis[nx][ny] = vis[x][y] + dist;
            q.push({nx, ny});
        }
    }
}

int main() {
    pair<int, int> top;
    cin >> N;
    cin >> top.first >> top.second; 

    // including padding for easier boundary checks
    vector<vector<int>> grid(N+2, vector<int>(N+2, 0));
    vector<vector<int>> vis(N+2, vector<int>(N+2, 51*51)); // 51 is the max distance
    for (int i = 0; i < N+2; i++) {
        for (int j = 0; j < N+2; j++) {
            if (i == 0 || j == 0 || i == N+1 || j == N+1) {
                grid[i][j] = 0;
                continue; 
            }
            cin >> grid[i][j];
        }
    }

    bfs(vis, grid);
    printGrid(grid);
    printGrid(vis);
    cout << vis[top.first][top.second];
}