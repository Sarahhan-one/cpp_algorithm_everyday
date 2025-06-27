#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int M, N, H;
    cin >> M >> N >> H; 

    vector<vector<vector<int>>> box(H, vector<vector<int>> (N, vector<int> (M, 0))); //3d map
    queue<vector<int>> q; //x, y, z, day
    int unripe = 0;
    for (int k = 0; k < H; k++) {
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                cin >> box[k][j][i];
                if (box[k][j][i] == 1) q.push({i, j, k, 0}); //while getting input, take the multiple starting points
                else if (box[k][j][i] == 0) unripe++; //also get the total unripe ones
            }
        }
    }  

    if (unripe == 0) { // if there's no unripe tomatos -> return 0
        cout << 0; 
        return 0;
    }

    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};

    int ans = 0;
    while (!q.empty()) {
        vector<int> temp;
        temp = q.front(); 
        q.pop(); 

        int x = temp[0];
        int y = temp[1];
        int z = temp[2];
        int day = temp[3];
        
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >= H) continue; //out of boundary
            if (box[nz][ny][nx] == 0) {
                box[nz][ny][nx] = 1; //mark as riped
                unripe--;
                q.push({nx, ny, nz, day+1});
            }
        }
        ans = day;
    }
    
    if (unripe == 0) {
        cout << ans; 
    } else { 
        cout << -1; //check if there's any unripe one -> return -1
    }
}