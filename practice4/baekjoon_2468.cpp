#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std; 

int main() {
    int N; 
    cin >> N; 

    vector<vector<int>> map(N, vector<int>(N, -1));
    vector<vector<bool>> vis(N, vector<bool>(N, false));
    int h_max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            h_max = max(map[i][j], h_max);
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int ans = 0;
    for (int h = 0; h < h_max; h++) {
        int cnt = 0; 
        queue<pair<int, int>> q; // x, y
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] <= h || vis[i][j]) continue;

                cnt++; 
                // cout << h << " " << cnt << endl;
                q.push({i, j}); 
                vis[i][j] = true; 

                while (!q.empty()) {
                    int x = q.front().first; 
                    int y = q.front().second; 
                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue; //boundary check
                        if (map[nx][ny] > h && !vis[nx][ny]) {
                            vis[nx][ny] = true; 
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        ans = max(ans, cnt);

        for (int i = 0; i < N; i++) {//reset the vis
            fill(vis[i].begin(), vis[i].end(), false);
        }
    }
    cout << ans;
}