#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>
using namespace std; 

int N, M;
vector<vector<int>> grid;
int totalZeros = 0;

void printPos(vector<pair<int, int>>& virusPos) {
    for (auto pos : virusPos) {
        cout << pos.first << " " << pos.second << '\n';
    }
    cout << '\n';
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans = INT_MAX;

void bfs(vector<pair<int, int>>& virusPos) {
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> vis(N, vector<bool>(N, false));

    for (auto pos : virusPos) {
        q.push({pos.first, pos.second, 0});
        vis[pos.first][pos.second] = true;
    }

    int cnt = 0;
    int maxTime = 0;
    while (!q.empty()) {
        auto [x, y, time] = q.front();
        q.pop();

        maxTime = max(maxTime, time);

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (grid[nx][ny] == 1) continue;
            if (vis[nx][ny]) continue;

            vis[nx][ny] = true;
            q.push({nx, ny, time + 1});
            cnt++;
        }
    }   

    if (cnt == totalZeros) {
        // cout << time << '\n';
        ans = min(ans, maxTime);
        return;
    }

}

void dfs(int start, vector<pair<int, int>>& virusPos, int digit, vector<pair<int, int>>& virusPossiblePos) {
    if (digit == M) {
        bfs(virusPos);
        // printPos(virusPos);
        return;
    }

    for (auto i = start; i < virusPossiblePos.size(); i++) {
        virusPos.push_back(virusPossiblePos[i]); 
        dfs(i+1 , virusPos, digit+1, virusPossiblePos);
        virusPos.pop_back();
    }
}

int main() {
    cin >> N >> M;

    grid.resize(N, vector<int>(N));
    vector<pair<int, int>> virusPossiblePos;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) virusPossiblePos.push_back({i, j});
            if (grid[i][j] == 0) totalZeros++;
        }
    }

    // printPos(virusPossiblePos);

    totalZeros = totalZeros + virusPossiblePos.size() - M;

    vector<pair<int, int>> virusPos;
    dfs(0, virusPos, 0, virusPossiblePos);

    if (ans == INT_MAX) cout << -1;
    else cout << ans;
}