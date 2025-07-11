#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int N;
vector<vector<int>> allPossibleComb = {};

// find the all possible combinations of the ingredients array - keep its idx
void findAllPossibleComb(int digit, vector<int>& temp, vector<bool>& vis, int idx) {
    if (temp.size() == digit) {
        allPossibleComb.push_back(temp);
        return;
    }

    int start = idx == 0 ? 0 : temp[idx-1];
    for (int i = start; i < N; i++) {
        if (vis[i]) continue; 
        vis[i] = true;
        temp.push_back(i); 
        findAllPossibleComb(digit, temp, vis, idx + 1);
        vis[i] = false;
        temp.pop_back();
    }
}

int main() {
    cin >> N; 

    vector<pair<int, int>> ingredients(N);
    for (int i = 0; i < N; i++) {
        int first, second;
        cin >> first >> second; 
        ingredients[i].first = first; 
        ingredients[i].second = second; 
    }

    for (int digit = 1; digit <= N; digit++) {
        vector<int> temp = {};
        vector<bool> vis(N, false);
        findAllPossibleComb(digit, temp, vis, 0);
    }

    // accumulater bitter and sour points though iterations
    
    
    int ans = INT_MAX;
    for (auto& comb : allPossibleComb) {
        int bitter = 0, sour = 1; // reset
        for (auto& idx : comb) {
            // cout << idx << " ";
            sour *= ingredients[idx].first;
            bitter += ingredients[idx].second;
            // cout << sour << " " << bitter << endl;
        }
        ans = min(ans, abs(sour - bitter));
        // cout << ans << endl;
    }


    // for (auto& comb : allPossibleComb) {
    //     for (auto& idx : comb) {
    //         cout << idx << " ";
    //     }
    //     cout << '\n';
    // }

    cout << ans;
}