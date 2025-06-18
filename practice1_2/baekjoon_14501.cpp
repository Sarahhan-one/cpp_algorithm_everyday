#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() {
    int N; 
    cin >> N; 

    vector<vector<int>> schedules; 
    for (int i = 0; i < N; i++) {
        int duration, cost, endDate; 
        cin >> duration >> cost; 

        endDate = i + duration; 
        if (endDate <= N) {
            schedules.push_back({i, endDate, cost});
        }
    }

    sort(schedules.begin(), schedules.end(), 
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

    //maximum profit on day n 
    vector<int> dp(schedules.size()+1, 0);

    for (int i = 1; i <= schedules.size(); i++) {
        int start = schedules[i-1][0];
        int end = schedules[i-1][1];
        int profit = schedules[i-1][2];

        dp[i] = dp[i-1]; // don't take this 

        //find the latest non-conflicting schedule + profit
        int nonConflicting = 0;
        for (int j = i-1; j >= 1; j--) {
            if (schedules[j-1][1] <= start) { //if current start >= end
                nonConflicting = j; 
                break; 
            }
        }

        //find the optimal ones
        dp[i] = max(dp[i], dp[nonConflicting] + profit);

    }

    cout << dp[schedules.size()]; 
} 