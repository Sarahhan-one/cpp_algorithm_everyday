#include <iostream>
#include <vector> 
using namespace std;

int N, M;

void printArr(vector<int>& temp) {
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << ' ';
    }
    cout << '\n';
}

void dfs(int digit, int start, vector<int>& temp) {
    if (digit == M) {
        printArr(temp);
        return;
    }

    for (int i = start; i <= N; i++) {
        temp.push_back(i);
        dfs(digit+1, i+1, temp);
        temp.pop_back();
    }
}

int main() {
    cin >> N >> M; 
    
    vector<int> temp;
    dfs(0, 1, temp);
}