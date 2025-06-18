#include <iostream>
#include <vector>
#include <limits.h>
#include <numeric>
using namespace std;

int main() {
    int target;
    cin >> target; 

    vector<int> dp(target+1, INT_MAX-1); 
    //base case 
    dp[3] = 1;
    dp[5] = 1; 

    for (int i = 6; i <= target; i++) {
        if ((dp[i-3]+1 != INT_MAX) || (dp[i-5]+1 != INT_MAX)) {
            dp[i] = min(dp[i-3]+1, dp[i-5]+1);
        }
    }
    
    if (dp[target] == INT_MAX-1) cout << -1; 
    else cout << dp[target];
}