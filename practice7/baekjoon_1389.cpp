#include <iostream>
#include <vector>
using namespace std;

#define MAX (10000)

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> d(N+1, vector<int>(N+1, MAX+1));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }

    for (int i = 1; i <= N; i++) {
        d[i][i] = 0;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j]; 
                }
            }
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << d[i][j];
    //     }
    //     cout << '\n';
    // }

    int minSum = MAX;
    int ans;
    for (int i = N; i >= 1; i--) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += d[i][j];
        }
        minSum = min(sum, minSum);
        if (minSum >= sum) ans = i;
    }
    cout << ans;
}