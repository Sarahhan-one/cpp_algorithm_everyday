#include <iostream> 
#include <vector>
#include <queue>
using namespace std; 

int main() {
    int M, N; 
    cin >> M >> N; 

    vector<vector<int>> map(M, vector<int>(N, 0)); // 0: path, 1: can't take this tile(either water or rock) 2: visited 3: destination - in perspective of hedgehog 
    queue<pair<int, int>> qWater; 
    queue<pair<int, int>> qPath; 
    pair<int, int> dest; 
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            char temp; 
            cin >> temp; 
            if (temp == 'D') { //destination
                dest = {i, j};
                map[i][j] = 3;
            }
            else if (temp == 'S') { //starting point
                qPath.push({i, j}); 
                map[i][j] = 2;
            }
            else if (temp == '*') { //water starting point
                qWater.push({i, j});
                map[i][j] = 1;
            }
            else if (temp == 'X') map[i][j] = 1; //rock
        }
    }  

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int cnt = 0;
    
    //water level expansion first, then path expansion - take turns 
    while (!qWater.empty() || !qPath.empty()) {
        int waterSize = qWater.size();
        for (int i = 0; i < waterSize; i++) {
            int x = qWater.front().first; 
            int y = qWater.front().second;
            qWater.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i]; 

                if (nx < 0 || ny < 0 || nx >= M || ny >= N)  continue;
                if (map[nx][ny] == 2 || map[nx][ny] == 0) {
                    map[nx][ny] = 1; 
                    qWater.push({nx, ny});
                }
            }
        }

        int pathSize = qPath.size();
        for (int i = 0; i < pathSize; i++) {
 
            if (qPath.front() == dest) { //exit condition
                cout << cnt; 
                return 0;
            }
            int x = qPath.front().first; 
            int y = qPath.front().second;
            qPath.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i]; 

                if (nx < 0 || ny < 0 || nx >= M || ny >= N)  continue;
                if (map[nx][ny] == 0 || map[nx][ny] == 3) {
                    map[nx][ny] = 2; 
                    qPath.push({nx, ny});
                }
            }
        }
        cnt++;
    }
    cout << "KAKTUS";
}