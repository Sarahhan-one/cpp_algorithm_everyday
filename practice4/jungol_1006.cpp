#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> map(M, vector<int> (N, 0));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int startX, startY, startDir; 
    cin >> startX >> startY >> startDir;
    int endX, endY, endDir;
    cin >> endX >> endY >> endDir; 

    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,-1}, {0,1}};

    queue<vector<int>> q; //x, y, dir
    q.push({startX, startY, startDir}); 
    map[startX][startY] = -1; 

    while (!q.empty()) {
        vector<int> temp = q.front();
        int x = temp[0];
        int y = temp[1];
        int dir = temp[2];

        if (x == endX && y == endY && dir == endDir) return; //exit condition

        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i].first; 
            int ny = y + dirs[i].second; 

            for (int j = 0; j < 3; j++) {//k can be either 1, 2, 3
                if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue; //boundary check 
                if (i+1 != dir) continue; //direction check
                
                    if (map[nx+j][ny+j] == 0) {

                    } 
            }

        }
    }

}