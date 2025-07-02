#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;

    vector<long long> dp(251, 0);
    dp[0] = 1;
    dp[1] = 1; 
    for (int i = 2; i <= 250; i++) {//if num is odd
        dp[i] = dp[i-1] + dp[i-2] * 2; 

    }

    while (cin >> num) {
        cout << dp[num] << "\n";
    }
    


}