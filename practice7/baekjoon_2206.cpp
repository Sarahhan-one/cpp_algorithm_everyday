#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < line.length(); j++){
            grid[i][j] = line[j] - '0';
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << grid[i][j];
    //     }
    //     cout <<'\n';
    // }

    queue<tuple<int, int, int, int>> q; //x, y, cost, isBroken (1 : there is a wall broken)
    vector<vector<vector<bool>>> vis(N, vector<vector<bool>>(M, vector<bool>(2, false))); //x, y, isBroken
    q.push({0, 0, 1, 0});
    vis[0][0][0] = true; 

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int ans = -1;

    while (!q.empty()) {
        auto [x, y, cost, isBroken] = q.front();
        q.pop();

        // cout << x << " " << y << " " << cost << " " << isBroken << '\n';

        if (x == N-1 && y == M-1) {
            ans = cost;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; 
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (vis[nx][ny][isBroken]) continue;

            if (grid[nx][ny] == 0) {
                q.push({nx, ny, cost+1, isBroken});
                vis[nx][ny][isBroken] = true;
            }
            else if (grid[nx][ny] == 1 && isBroken == 0) {
                q.push({nx, ny, cost+1, 1});
                vis[nx][ny][1] = true;
            }
            
        }
    }
    cout << ans;
    return 0;

}