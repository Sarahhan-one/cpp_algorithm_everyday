#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void dfs (int n, int digit, vector<int>& temp, vector<vector<int>>& array) {
    if (digit < (n/2)) {
        array.push_back(temp);
    }

    if (digit == (n/2)) {
        array.push_back(temp);
        return;
    }

    for (int i = temp[digit-1]; i < n - 1; i++) {
        temp.push_back(i+1);
        dfs(n, digit+1, temp, array);
        temp.pop_back();
    }
}

int main() {
    int N; 
    cin >> N; 

    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> temp;
    vector<vector<int>> combinations;

    for (int i = 0; i < N; i++) {
        temp.push_back(i);
        dfs(N, 1, temp, combinations);
        temp.pop_back();
    }
    
    // for (auto combination : combinations) {
    //     for (auto comb : combination) {
    //         cout << comb;
    //     }
    //     cout << '\n';
    // }

    int ans = INT_MAX;
    for (const auto& teamOne : combinations) {
        vector<int> teamTwo;
        vector<bool> used(N, false);

        for (int member : teamOne) {
            used[member] = true;
        }

        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                teamTwo.push_back(i);
            }
        }

        int teamOneScore = 0;
        int teamTwoScore = 0;

        for (int j = 0; j < teamOne.size()-1; j++) {
            for (int k = j+1; k < teamOne.size(); k++) {
                teamOneScore += (grid[teamOne[j]][teamOne[k]] + grid[teamOne[k]][teamOne[j]]);
            }
        }

        for (int j = 0; j < teamTwo.size()-1; j++) {
            for (int k = j+1; k < teamTwo.size(); k++) {
                teamTwoScore += (grid[teamTwo[j]][teamTwo[k]] + grid[teamTwo[k]][teamTwo[j]]);
            }
        }
        ans = min(ans, abs(teamOneScore - teamTwoScore));

        // cout << teamOneScore << " " << teamTwoScore << '\n';
    }
    cout << ans;
    return 0;

}