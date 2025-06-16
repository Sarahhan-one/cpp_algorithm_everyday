#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() {
    int N; 
    cin >> N; 

    vector<vector<int>> schedules; 
    for (int i = 0; i < N; i++) {
        int duration, profit, endDate; 
        cin >> duration >> profit; 

        endDate = i + 1 + duration; 
        schedules.push_back({endDate, profit}); //day (0 - N-1) : (1 - N)
    }

    //dp[i] : the maximum profit we can make from day i to the end
    vector<int> dp(schedules.size()+2, 0);

    for (int i = N; i >= 1; i--) { //for each date
        int end = schedules[i-1][0];
        int profit = schedules[i-1][1];

        //not do the call 
        dp[i] = dp[i+1];
        if (end <= N+1) { //out-of-bound
            dp[i] = max(dp[i], profit + dp[end]); //do the call
        }

        // cout << "Day " << i << ": end=" << end << ", profit=" << profit << ", dp[" << i << "]=" << dp[i] << endl;
    }
    cout << dp[1]; 
} 