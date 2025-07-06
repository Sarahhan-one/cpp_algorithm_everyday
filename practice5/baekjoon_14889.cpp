#include <iostream> 
#include <vector>
#include <limits.h>
using namespace std;

int N;
int possNum;
vector<vector<int>> teams; // combination of making two teams with N people
vector<vector<int>> peopleComb; // combination of making a pair among the people in the team -> in idx


void dfs(int idx, vector<int>& temp) {
    // if (temp.size() == 1) return;

    if (temp.size() == N/2) { //exit condition
        teams.push_back(temp);
        temp.pop_back();
        return;
    }

    for (int i = idx; i < N; i++) {
        temp.push_back(i); 
        dfs(i + 1, temp);     
    }
    temp.pop_back();
}

void dfs2(int idx, vector<int>& temp) {
    if (temp.size() == 2) { //exit condition
        peopleComb.push_back(temp);
        return;
    }

    for (int i = idx; i < N/2; i++) {
        temp.push_back(i); 
        dfs2(i + 1, temp);    
        temp.pop_back();
    }
}

int main() {
    cin >> N; 

    vector<vector<int>> stats(N, vector<int> (N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> stats[i][j];
        }
    }

    vector<bool> vis(N, false);
    vector<int> temp;
    dfs(0, temp); // find all possible combinations to make the two teams

    temp = {}; //reinitialize the temp to re-use
    dfs2(0, temp); // find all possible combination of making a pair among the people in the team, keep that in idx

    int ans = INT_MAX;
    for (int i = 0; i < teams.size()/2; i++) {
        vector<int> teamOne = teams[i];
        vector<int> teamTwo = teams[teams.size() - 1 -i];

        int diff = 0;
        int firstTeam = 0, secondTeam = 0;
        int firstPerson, secondPerson;
        for (auto& idx : peopleComb) {
            firstPerson = teamOne[idx[0]];
            secondPerson = teamOne[idx[1]];

            firstTeam += stats[firstPerson][secondPerson];
            firstTeam += stats[secondPerson][firstPerson];

            firstPerson = teamTwo[idx[0]];
            secondPerson = teamTwo[idx[1]];

            secondTeam += stats[firstPerson][secondPerson];
            secondTeam += stats[secondPerson][firstPerson];
        }

        // cout << firstTeam << " " << secondTeam << endl;
        diff = abs(firstTeam - secondTeam);
        ans = min(ans, diff);
    }



    cout << ans;
    //for debugging
    // for (auto& a : teams) {
    //     for (auto& c : a) {
    //         cout << c << ' ';
    //     }
    //     cout << '\n';
    // }
} 