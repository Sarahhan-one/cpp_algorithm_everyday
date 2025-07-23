#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; 
    cin >> N;

    vector<pair<int, int>> dp(N+1); //row, col
    dp[1] = {1, 1};

    if (N == 1) {
        cout << "1/1";
        return 0;
    }

    bool isUp = true;
    for (int i = 2; i <= N; i++) {
        int row = dp[i-1].first; 
        int col = dp[i-1].second;
        
        if (row == 1 && isUp) {
            dp[i] = {row, col+1};
            isUp = false;
            continue;
        }
        if (col == 1 && !isUp) {
            dp[i] = {row+1, col};
            isUp = true;
            continue;
        }

        if (isUp) {
            dp[i] = {row-1, col+1};
        } 
        else {
            dp[i] = {row+1, col-1};
        }
        

    }

    cout << dp[N].first << "/" << dp[N].second;
}