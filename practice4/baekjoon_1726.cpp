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

    vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}}; //0-East, 1-West, 2-South, 3-North

    startX--; startY--; endX--; endY--; //convert to 0-indexed
    startDir--; endDir--; //convert to 0-indexed

    queue<vector<int>> q; //x, y, dir, dist
    vector<vector<vector<bool>>> vis(M, vector<vector<bool>>(N, vector<bool>(4, false))); //visited[x][y][dir]
    q.push({startX, startY, startDir, 0}); //at start position
    vis[startX][startY][startDir] = true; //mark as visited

    while (!q.empty()) {
        vector<int> temp = q.front();
        q.pop();
        
        int x = temp[0];
        int y = temp[1];
        int dir = temp[2];
        int dist = temp[3];
        

        if (x == endX && y == endY && dir == endDir) {//exit condition
            cout << dist;
            return 0;
        }

        int nx = x; 
        int ny = y; 
        //Try moving forward 1, 2, 3 steps
        for (int k = 1; k <= 3; k++) {
            nx += dirs[dir].first; 
            ny += dirs[dir].second; 

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) break; //boundary check
            if (map[nx][ny] != 0) break; //if it is not the route, break
            if (vis[nx][ny][dir]) continue; //already visited - but continue checking further steps

            vis[nx][ny][dir] = true; 
            q.push({nx, ny, dir, dist+1}); //push the next position
        }

        //turn either left or right 
        // Turn left
        int leftDir;
        if (dir == 0) leftDir = 3;
        else if (dir == 1) leftDir = 2;
        else if (dir == 2) leftDir = 0;
        else leftDir = 1;
        if (!vis[x][y][leftDir]) { //check it is already visited
            vis[x][y][leftDir] = true;
            q.push({x, y, leftDir, dist + 1});
        }

        // Turn right
        int rightDir;
        if (dir == 0) rightDir = 2;
        else if (dir == 1) rightDir = 3;
        else if (dir == 2) rightDir = 1;
        else rightDir = 0;
        if (!vis[x][y][rightDir]) {
            vis[x][y][rightDir] = true;
            q.push({x, y, rightDir, dist + 1});
        }
    }
    return 0;
}