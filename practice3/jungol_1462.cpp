#include <iostream>
#include <vector>
#include <queue> 
#include <utility>
using namespace std;

//Longest shortest path between any two land cells on the map
int ans = 0;

typedef struct _cell {
    pair<int, int> location; 
    int dist;
} cell; 

int main() {
    int N, M; 
    cin >> N >> M; 
    
    vector<vector<char>> map(N, vector<char> (M, 0)); 
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    } 

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<cell> q; //x, y, dist
    vector<vector<bool>> vis(N, vector<bool> (M, false));

    for (int i = 0; i < N; i++) { //for every cells in the map
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'L') { //if we find the land, begin the BFS
                q.push({{i, j}, 0}); //startint point
                vis[i][j] = true; 

                int max_dist = 0;
                while (!q.empty()) {
                    int x = q.front().location.first;
                    int y = q.front().location.second;
                    int dist = q.front().dist;
                    q.pop(); 

                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if (min(nx, ny) < 0 || nx >= N || ny >= M) continue; 
                        if (!vis[nx][ny] && map[nx][ny] == 'L') {
                            vis[nx][ny] = true; 
                            q.push({{nx, ny}, dist+1});
                        }
                    }
                    max_dist = max(max_dist, dist);
                }
                if (max_dist > ans) ans = max_dist;
                for (auto& row : vis) {
                    fill(row.begin(), row.end(), false);
                }
            }
        }
    }
    cout << ans;

}