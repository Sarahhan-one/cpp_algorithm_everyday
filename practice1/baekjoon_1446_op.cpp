#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std; 

int main() {
    int N, D;
    cin >> N >> D; 
    
    vector<vector<int>> shortcuts;
    
    for (int i = 0; i < N; i++) {
        int pairFirst, pairSecond, sc;
        cin >> pairFirst >> pairSecond >> sc;
        
        if (pairFirst >= pairSecond || (D - pairSecond) < 0 ) continue; // discard if end point exceeds D
        shortcuts.push_back({pairFirst, pairSecond, sc});
    }

    //but.. we might find better shorcuts later that could improve earlier positions
    sort(shortcuts.begin(), shortcuts.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];});

    vector<int> dp(D+1);
    for (int i = 0; i <= D; i++) { // base case
        dp[i] = i;
    }

    for (auto& shortcut : shortcuts) {
        int start = shortcut[0]; 
        int end = shortcut[1];
        int sc = shortcut[2];   
        
        int cur = dp[start] + sc;
        if (cur < dp[end]) { //then better to take this shorcut! 
            int j = 0; 
            for (int i = end; i <= D; i++) {
                dp[i] = cur + (j++);
            }
        }
    }
    cout << dp[D];
}