#include <iostream>
#include <vector> 
#include <queue> 
#include <tuple>
#include <algorithm>
using namespace std; 

vector<int> p;
int find(int x) {
    if (p[x] < 0) return x;
    else return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return true;
    
    if (p[v] < p[u]) swap(u, v);
    if (p[v] == p[u]) p[u]--; 
    p[v] = u;
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    queue<pair<int, int>> qq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 0) qq.push({i, j});
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<vector<bool>> vis(N, vector<bool>(M, false));
    queue<pair<int, int>> q; //x, y
    int colour = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 0) continue;
            if (vis[i][j]) continue;

            q.push({i, j});
            vis[i][j] = true;
            grid[i][j] = colour;
            // cout << i << " " << j << " " << colour << endl;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                    if (grid[nx][ny] == 0) continue;
                    if (vis[nx][ny]) continue;

                    vis[nx][ny] = true;
                    grid[nx][ny] = colour;
                    q.push({nx, ny});
                }
            }
            colour++;
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    vector<tuple<int, int, int>> nodes;
    while (!qq.empty()) {
        auto [x, y] = qq.front();
        qq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            int n = 0;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue; 

            while (nx >= 0 && ny >= 0 && nx < N && ny < M && grid[nx][ny] == 0) {
                nx += dx[i];
                ny += dy[i];
                n++;
            }

            if (nx >= 0 && ny >= 0 && nx < N && ny < M && grid[nx][ny] != 0 && grid[x][y] != 0 && n >= 2) {
                nodes.push_back({n, grid[x][y], grid[nx][ny]});
            }
        }
    }
    
    // for (auto node : nodes) {
    //     auto [dist, node1, node2] = node;
    //     cout << dist << node1 << node2 << endl;
    // }

    p.resize(colour, -1);
    sort(nodes.begin(), nodes.end());
    int ans = 0;
    for (auto node : nodes) {
        auto [dist, nodeOne, nodeTwo] = node;
        if (uni(nodeOne, nodeTwo)) continue;

        ans += dist;
    }

    int cnt = 0;
    for (int i = 1; i <= colour; i++) {
        if (p[i] < 0) cnt++;
    }

    if (cnt < 2) cout << ans; 
    else cout << -1; 

    return 0;

}