#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> ans;
string minAns = "999999999";
string maxAns = "0"; 

// int vectorToInt(vector<int>& temp) {
//     int num = 0; 
//     for (int i = 0; i < temp.size(); i++) {
//         num = num * 10 + temp[i];
//     }
//     return num;
// }

void printVector(vector<int>& temp) {
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i];
    }
    cout << '\n';
}

void fillIn(vector<int>& temp, vector<bool>& nextIsBigger, int idx, vector<bool>& vis) {
    if (idx == N) { //exit condition
        // for (int i = 0; i < temp.size(); i++) {
        //     cout << temp[i];
        // }
        // cout << endl;
        ans.push_back(temp);
        return;
    }

    int currNum = temp[idx]; 
    bool currSign = nextIsBigger[idx];
    if (currSign) { // if the next one should be bigger
        for (int j = currNum + 1; j <= 9; j++) {
            if (vis[j]) continue; 
            vis[j] = true;
            temp.push_back(j); 
            fillIn(temp, nextIsBigger, idx+1, vis);
            temp.pop_back();
            vis[j] = false;
        }
    }
    else { // if the next one should be smaller
        for (int j = 0; j < currNum; j++) {
            if (vis[j]) continue; 
            vis[j] = true;
            temp.push_back(j); 
            fillIn(temp, nextIsBigger, idx+1, vis);
            temp.pop_back();
            vis[j] = false;
        }  
    }
}

int main() {

    cin >> N; 
    
    vector<bool> nextIsBigger(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c; 
        if (c == '<') nextIsBigger[i] = true;
        else if ( c == '>') nextIsBigger[i] = false;
    }


    for (int i = 0; i <= 9; i++) {
        vector<int> temp;
        vector<bool> vis(10);
        
        temp.push_back(i);
        vis[i] = true;
        fillIn(temp, nextIsBigger, 0, vis);
    }

    printVector(ans[ans.size()-1]);
    printVector(ans[0]);


    // for (int i = 0; i < N; i++) {
    //     cout << nextIsBigger[i] << endl;
    // }
} 