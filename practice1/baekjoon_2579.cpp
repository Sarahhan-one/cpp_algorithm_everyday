#include <iostream> 
#include <vector>
using namespace std;
//rules:
//1. +1 or +2 steps at once 
//2. not three or more consecutive steps
//3. the last step must included

int main() {
    int N; 
    cin >> N; 
    vector<int> steps(N); 
    for (int i = 0; i < N; i++) {
        cin >> steps[i];
    }

    //base cases
    if (N == 1) {
        cout << steps[0]; 
        return 0; 
    }
    if (N == 2) {
        cout << steps[0] + steps[1];
        return 0;
    }

    vector<int> dp1(N+2, 0); //track if we came via +1 step
    vector<int> dp2(N+2, 0); //track if we came via +2 step
    dp1[N-1] = steps[N-1];
    dp2[N-1] = steps[N-1];

    for (int i = N-2; i >= 0; i--) {
        dp2[i] = steps[i] + max(dp1[i+2], dp2[i+2]); //take +2 steps
        dp1[i] = steps[i] + dp2[i+1]; //take +1 step - no three or more consecutive steps
    }

    //it can start from either step0 or step1
    int res = max(max(dp1[0], dp2[0]), max(dp1[1], dp2[1]));
    cout << res;
}

