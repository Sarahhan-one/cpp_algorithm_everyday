#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// apply the rectangle areas onto the map 
// solve it in bfs
int main() {
    int M, N, K;
    cin >> M >> N >> K; 

    vector<vector<bool>> map(N, vector<bool>(M, false));
    for (int i = 0; i < K; i++) {
        int y1, x1, y2, x2; 
        cin >> y1 >> x1 >> y2 >> x2; 
        // mark rectangles
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                map[y][x] = true; 
            }
        }
    }   

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    //bfs
    int size = 0;
    int cnt = 0;
    vector<int> ans;
    queue<pair<int, int>> q; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j]) continue; //if it's either wall or visited, continue

            q.push({i, j}); 
            map[i][j] = true; 

            while (!q.empty()) {
                int y = q.front().first; 
                int x = q.front().second;
                q.pop();
                size++;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                    if (!map[ny][nx]) { //if it's not wall and not visited 
                        map[ny][nx] = true; 
                        q.push({ny, nx});
                    }
                } 
            }
            ans.push_back(size);
            size = 0;
            cnt++;
        }
    }
    sort(ans.begin(), ans.end());

    cout << cnt << "\n";
    for (auto& a : ans) {
        cout << a << " ";
    }
}