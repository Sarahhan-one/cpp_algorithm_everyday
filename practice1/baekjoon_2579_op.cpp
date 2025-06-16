#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> steps(N);
    for (int i = 0; i < N; i++) {
        cin >> steps[i];
    }
    
    if (N == 1) {
        cout << steps[0] << endl;
        return 0;
    }
    if (N == 2) {
        cout << steps[0] + steps[1] << endl;
        return 0;
    }
    
    // Use your backward approach but with proper state tracking
    vector<int> dp1(N+2, 0); // dp1[i] = max score from step i, last move was +1
    vector<int> dp2(N+2, 0); // dp2[i] = max score from step i, last move was +2
    
    // Base case: we must end at step N-1
    dp1[N-1] = steps[N-1];
    dp2[N-1] = steps[N-1];
    
    // Traverse backwards like your original approach
    for (int i = N-2; i >= 0; i--) {
        // Option 1: Take +2 step from current position
        dp2[i] = steps[i] + max(dp1[i+2], dp2[i+2]);
        
        // Option 2: Take +1 step from current position
        // But we can only do this if the next step came from +2 (to avoid 3 consecutive)
        dp1[i] = steps[i] + dp2[i+1];
    }
    
    // Start from ground (before step 0), we can go to step 0 or step 1
    int result = max(max(dp1[0], dp2[0]), max(dp1[1], dp2[1]));
    cout << result << endl;
    
    return 0;
}