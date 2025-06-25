#include <iostream>
#include <vector> 
using namespace std; 
int N;
int ans; 

// process the one queen per row 
// place a queen and reculsive to the next row
// backtrack the vis marks after each recursive call 
// keep track of diag1[rows - i + N + 1] diag2[rows + i]
void dfs(int rows, vector<bool>&cols, vector<bool>&diag1, vector<bool>&diag2) {
    if (rows == N) {
        ans++;
        return; 
    }

    for (int i = 0; i < N; i++) {
        if(cols[i] || diag1[rows - i + N + 1] || diag2[rows + i]) continue;
        cols[i] = true; diag1[rows - i + N + 1] = true; diag2[rows + i] = true;
        dfs(rows+1, cols, diag1, diag2); 
        cols[i] = false; diag1[rows - i + N + 1] = false; diag2[rows + i] = false;
    }
}


int main() {
    cin >> N; 
    vector<bool> cols(N, false);
    vector<bool> diag1(N, false);
    vector<bool> diag2(N, false);

    int rows = 0;
    dfs(rows, cols, diag1, diag2); 

    cout << ans;

}