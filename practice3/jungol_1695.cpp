#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, num;
vector<int> dx = {0, 1, 0, -1}; // down, left, up, right
vector<int> dy = {1, 0, -1, 0};

void recursion(int x, int y, vector<vector<int>>& grid, int& cnt) {
    grid[x][y] = -1; // mark as visited
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i]; 
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // out of bounds
        if (grid[nx][ny] == 1) {
            recursion(nx, ny, grid, cnt);
        }
    }
}

int main() { 
    cin >> N; 

    vector<vector<int>> grid(N, vector<int> (N, -1));
    vector<vector<bool>> vis(N, vector<bool> (N, false)); 
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row; 
        for (int j = 0; j < N; j++) {
            grid[i][j] = row[j] - '0';
        }
    }

    int num = 0;
    vector<int> cnts;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (grid[x][y] == 1) {
                int cnt = 0; 
                num++; 
                recursion(x, y, grid, cnt);
                cnts.push_back(cnt); 
            }
        }
    }

    sort(cnts.begin(), cnts.end());
    cout << num << endl;
    for (auto& cnt : cnts) {
        cout << cnt << endl;
    }

    
}