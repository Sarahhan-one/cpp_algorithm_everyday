#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

int T; 
int M, N, K; 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans = 0;

void dfs(int x, int y, vector<vector<int>>& map) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (min(nx, ny) < 0 || nx >= M || ny >= N) continue; 
        if (map[nx][ny] == 1) {
            map[nx][ny] = 2;
            dfs(nx, ny, map);
        }
    }
}

int main() {
    cin >> T; 

    while(T--) {
        cin >> M >> N >> K;

        vector<vector<int>> map(M, vector<int>(N, 0)); 
        for (int i = 0; i < K; i++) {
            int x, y; 
            cin >> x >> y; 
            map[x][y] = 1; 
        }

        //find the number of groups that are consist of 1s
        for (int x = 0; x < M; x++) {
            for (int y = 0; y < N; y++) {
                if (map[x][y] == 1) {
                    dfs(x, y, map);
                    ans++;
                }
            }
        }

        cout << ans << "\n";
        ans = 0;
    }
}