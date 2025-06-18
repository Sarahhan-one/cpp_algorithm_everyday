#include <iostream> 
#include <vector>
#include <queue> 
#include <stdbool.h>
using namespace std; 
int M, N; 

typedef struct _node { 
    int x; 
    int y;
}node_t; 

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// multiple starting points BFS 
int bfs(vector<vector<int>>& grid) { 
    queue<node_t> q;

}

int main() { 
    cin >> M >> N;

    vector<vector<int>> grid(N, vector<int> (M, 0));
    vector<vector<int>> vis(N, vector<int> (M, 0)); 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int temp; 
            if (temp == 1) grid[i][j] = 1;
        }
    }

    // cout << bfs(); 
}