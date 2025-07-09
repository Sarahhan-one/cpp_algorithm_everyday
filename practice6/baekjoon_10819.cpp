#include <iostream>
#include <vector>
using namespace std;

int N;

// find the all possible array idx orders
void findPossibleOrder(vector<vector<int>>& possibleOrder, vector<int>& temp, vector<bool>& vis) {
    if (temp.size() == N) {
        possibleOrder.push_back(temp);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        temp.push_back(i); 
        findPossibleOrder(possibleOrder, temp, vis);
        vis[i] = false;
        temp.pop_back();
    }
}

// find the maximum of difference
int ans = 0;
void findMax(vector<int>& array, vector<vector<int>>& possibleOrder) {
    for (int i = 0; i < possibleOrder.size(); i++) {
        int temp = 0;
        for (int j = 0; j <= N-2; j++) {
            temp += abs(array[possibleOrder[i][j]] - array[possibleOrder[i][j+1]]);
        }
        ans = max(ans, temp);
    }
}

int main() {
    cin >> N; 
    
    vector<int> array(N);
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    vector<vector<int>> possibleOrder;
    vector<int> temp;
    vector<bool> vis(N, false);
    findPossibleOrder(possibleOrder, temp, vis);

    findMax(array, possibleOrder);
    
    cout << ans;
}