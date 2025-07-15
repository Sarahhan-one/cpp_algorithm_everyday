#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; 
    cin >> N; 
    
    vector<vector<int>> grid(N, vector<int> (N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << grid[i][j];
    //     }
    //     cout << '\n';
    // }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][k] + grid[k][j] == 2) grid[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << ' ';
        }
        if (i != N-1) cout << '\n';
    }
} 