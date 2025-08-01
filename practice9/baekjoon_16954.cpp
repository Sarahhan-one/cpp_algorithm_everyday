#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<vector<char>> grid;

bool bfs() {
    int dx[9] = {1, 1, 1, -1, -1, -1, 0, 0, 0};
    int dy[9] = {0, 1, -1, 0, 1, -1, 0, 1, -1};

    queue<tuple<int, int, int>> q; // x, y, cnt
    q.push({7,0,0}); //starting point 

    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();

        if (x-cnt >= 0 && grid[x-cnt][y] != '.') continue; // if a wall interferes the character posisiton

        if (cnt == 8) return 1; // at most 8 seconds later, all walls will disappear
        if (x == 0 && y == 7) return 1; // reaches destination

        for (int i = 0; i < 9; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue; //boundary check
            if (nx-cnt >= 0 && grid[nx-cnt][ny] != '.') continue;

            q.push({nx, ny, cnt+1});
        }
    }
    return 0;
}

int main() {
    grid.assign(8, vector<char>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j];
        }
    }

    cout << bfs();
}