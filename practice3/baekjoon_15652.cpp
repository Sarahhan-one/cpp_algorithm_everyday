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
    
    int start = (digit == 0) ? 1 : arr[digit-1];
    for (int i = start; i <= N; i++) {
        arr[digit] = i;  
        backtrack(digit+1, vis, arr);
    }
}

int main() {
    cin >> N >> M;
    
    vector<bool> vis(N+1, false); 
    vector<int> arr(M); 
    backtrack(0, vis, arr);
    return 0;
}