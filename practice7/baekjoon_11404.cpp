#include <iostream>
#include <vector>
using namespace std;

#define INF (10000000)

int main() {
    int N, M; 
    cin >> N;
    cin >> M;

    vector<vector<int>> grid(N, vector<int>(N, INF));
    for (int i = 0; i < M; i++) {
        int cityOne, cityTwo, cost; 
        cin >> cityOne >> cityTwo >> cost; 

        grid[cityOne-1][cityTwo-1] = min(grid[cityOne-1][cityTwo-1], cost);
    }

    for (int i = 0; i < N; i++) {
        grid[i][i] = 0;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][k] + grid[k][j] < grid[i][j]) grid[i][j] = grid[i][k] + grid[k][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == INF) cout << 0 << ' ';
            else cout << grid[i][j] << ' ';
        }
        if (i != N-1) cout << '\n';
    }
}