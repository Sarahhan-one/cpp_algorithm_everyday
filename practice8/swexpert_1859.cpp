#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M; 
    cin >> N; 
    for (int i = 1; i <= N; i++) {
        cin >> M;
        
        vector<int> prices(M);
        for (int i = 0; i < M; i++) {
            cin >> prices[i];
        }

        long max = 0;
        long ans = 0;
        for (int i = M-1; i >= 0; i--) {
            if (max < prices[i]) max = prices[i];
            else ans += max - prices[i];
        }
        cout << "#" << i << ' ' << ans << '\n';
    }

}