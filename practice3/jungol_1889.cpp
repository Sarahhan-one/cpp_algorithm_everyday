#include <iostream>
#include <vector> 
using namespace std; 
int N;
vector<bool> rows, cols, diag1, diag2;
int ans = 0;

void dfs(int row, int col) {
    if (row == N) {
        ans++;
        return; 
    }

    for (int i = 0; i < N; i++) { //iterate through cols
        dfs()
    }

    
}

int main() {

    cin >> N; 

    vector<bool> rows(N, false);
    vector<bool> cols(N, false);
    vector<bool> rows(N, false);
    vector<bool> cols(N, false);
    
    dfs(0);   


    cout << ans;
}