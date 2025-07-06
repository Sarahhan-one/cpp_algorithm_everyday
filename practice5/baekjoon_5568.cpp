#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int N, K; 
set<string> ans; 

void recursion(vector<int>& cards, vector<bool>& vis, string& temp, int numCnt) {
    // if (numCnt < K && numCnt >= 2) {
    //     ans.insert(temp);
    // }

    if (numCnt == K) {
        ans.insert(temp);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        vis[i] = true; 
        numCnt++;
        string new_temp = temp + to_string(cards[i]); 
        recursion(cards, vis, new_temp, numCnt); 
        vis[i] = false;
        numCnt--;
    }
}

int main() {
    cin >> N; 
    cin >> K; 

    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    vector<bool> vis(N, false); 
    string temp = "";
    recursion(cards, vis, temp, 0);


    // for (auto& t : ans) {
    //     cout << t << endl;
    // }
    cout << ans.size();
}

 