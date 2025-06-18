#include <iostream> 
#include <vector>
using namespace std; 

int N, M;

void printArr(vector<int>& arr) {
    for (int i = 0; i < M; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void backtrack(int digit, vector<bool>& vis, vector<int>& arr) {
    // base case
    if (digit >= M) {
        printArr(arr);
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            arr[digit] = i;  
            vis[i] = true;
            backtrack(digit+1, vis, arr);
            vis[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    
    vector<bool> vis(N+1, false); 
    vector<int> arr(M); 
    backtrack(0, vis, arr);
    return 0;
}