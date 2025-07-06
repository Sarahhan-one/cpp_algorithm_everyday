#include <iostream>
#include <vector>
using namespace std; 

int K;


void recursion(const vector<int>& testcase, vector<bool>& vis, vector<int>& temp, int index, vector<vector<int>>& ans) {
    if (temp.size() == 6) {//exit condition 
        ans.push_back(temp); 
        return;
    }

    for (int i = index; i < K; i++) {
        if (vis[i]) continue;
        vis[i] = true; 
        vector<int> newTemp = temp;
        newTemp.push_back(testcase[i]);
        recursion(testcase, vis, newTemp, i+1, ans);
        vis[i] = false;
    }
}

void printArr(vector<vector<int>>& ans) {
    for (auto& i : ans) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> K;
    while (K != 0) {
        vector<vector<int>> ans; 
        vector<int> testcase(K);
        for (int i = 0; i < K; i++) {
            cin >> testcase[i];
        }

        vector<int> temp; 
        vector<bool> vis(K, false);
        recursion(testcase, vis, temp, 0, ans);

        printArr(ans);

        cin >> K;
    }    
}