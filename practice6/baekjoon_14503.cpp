#include <iostream>
#include <vector>
using namespace std;

int N, M;
int dc[4] = {0, 1, 0, -1}; // N, E, S, W
int dr[4] = {-1, 0, 1, 0};

bool boundaryCheck(int R, int C) {
    if (R < 0 || C < 0 || R >= N || C >= M) return false;
    return true;
}

void cleaning(int& roomCleaned, vector<vector<int>>& grid, int currR, int currC, int currD, bool& allCleaned) {
    
    // cout << currR << " " << currC << " " << currD << endl;
    
    if (grid[currR][currC] == 0) {
        grid[currR][currC] = 2; // 2 : cleaned, mark as cleaned
        roomCleaned++;
    }

    int nextD, nextR, nextC; 
    for (int i = 0; i < 4; i++) {
        nextD = (currD + 3) % 4; // rotate counter-clockwise
        nextR = currR + dr[nextD];
        nextC = currC + dc[nextD];

        currD = nextD; // we are checking different directions only
        
        if (!boundaryCheck(nextR, nextC)) continue;
        if (grid[nextR][nextC] == 0) {
            cleaning(roomCleaned, grid, nextR, nextC, nextD, allCleaned); 
            allCleaned = false;
            break;
        }
    }

    if (allCleaned) {
        allCleaned = true;

        int moveD = (currD + 2) % 4; // opposite direciton - don't pass this as robot's direction
        nextR = currR + dr[moveD];
        nextC = currC + dc[moveD];

        if (boundaryCheck(nextR, nextC) && grid[nextR][nextC] != 1) cleaning(roomCleaned, grid, nextR, nextC, currD, allCleaned);
        else return;
    }
}   

int main() {
    cin >> N >> M;
    int startR, startC, startD; 
    cin >> startR >> startC >> startD;

    vector<vector<int>> grid(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int roomCleaned = 0;
    bool alreadyCleaned = true;
    cleaning(roomCleaned, grid, startR, startC, startD, alreadyCleaned);

    cout << roomCleaned;
} 