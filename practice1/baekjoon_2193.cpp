#include <iostream> 
using namespace std;

//pinary number - 1. don't start with 0 2. no consecutive 1 
//starting number is 1
// 1 10 100 101 1000 1001
int main() {
    int N;
    cin >> N; 

    // define the num of valid sequences for i length ending 0 : dp[i][0]
    // similarily ending 1 : dp[i][1]
    long long dp[N+1][2]; 
    dp[1][0] = 0; dp[1][1] = 1; 

    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1]; 
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[N][0] + dp[N][1] << endl; 
    return 0;
}