#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool checkMid(vector<int>& budgets, int mid, int setBudget) {
    int sum = 0;
    for (auto budget : budgets) {
        sum += min(budget, mid);
    }

    return sum <= setBudget;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> budgets(N);
    int maxBudget = 0;
    for (int i = 0; i < N; i++) {
        cin >> budgets[i];
        maxBudget = max(maxBudget, budgets[i]);
    }
    int setBudget; 
    cin >> setBudget;

    //case 1 
    int sum = 0;
    for (auto budget : budgets) {
        sum += budget;
    }
    if (sum <= setBudget) {
        cout << maxBudget;
        return 0;
    }

    //case 2
    int start = 0; 
    int end = maxBudget;

    set<int> midHistory;
    // int mid;
    int ans = 0;
    while (start <= end) {
        int mid = (start + end)/2;

        // if (midHistory.find(mid) != midHistory.end()) break;
        // midHistory.insert(mid);

        // cout << mid << endl;

        if (checkMid(budgets, mid, setBudget)) { start = mid+1; ans = mid; }
        else end = mid - 1;
    }

    cout << ans;
    
    return 0;
}