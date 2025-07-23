#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
int N, M;

int checkZeros(vector<vector<int>>& grid) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 0) cnt++; 
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    vector<pair<int, int>> zeroPos;
    queue<pair<int, int>> virusPos;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 0) { 
                zeroPos.push_back({i,j}); 
            }
            if (grid[i][j] == 2) { 
                virusPos.push({i, j}); //x, y
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int ans = 0;
    int n = zeroPos.size();
    for (int i = 0; i < n - 2; i++) {
        for (int j = i+1; j < n -1; j++) {
            for (int k = j+1; k < n; k++) {
                auto gridCopy = grid;
                auto q = virusPos;

                gridCopy[zeroPos[i].first][zeroPos[i].second] = 1;
                gridCopy[zeroPos[j].first][zeroPos[j].second] = 1;
                gridCopy[zeroPos[k].first][zeroPos[k].second] = 1;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int m = 0; m < 4; m++) {
                        int nx = x + dx[m];
                        int ny = y + dy[m];

                        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                        if (gridCopy[nx][ny] != 0) continue;

                        gridCopy[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
                ans = max(ans, checkZeros(gridCopy));
            }
        }
    }
    cout << ans;
}