#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std; 

//cut where there's largest gap between sensors
int main() {
    int N, K;
    cin >> N >> K; 
    vector<int> sensors(N);
    for (int i = 0; i < N; i++) {
        cin >> sensors[i];
    }

    if (K >= N) { //exception
        cout << 0; 
        return 0;
    }

    sort(sensors.begin(), sensors.end());

    vector<int> gaps(N-1);
    for (int i = 0; i < N - 1; i++) {
        gaps[i] = abs(sensors[i+1] - sensors[i]);
    }

    sort(gaps.begin(), gaps.end());

    for (int i = 0; i < K - 1; i++) {
        gaps.pop_back();
    }

    cout << accumulate(gaps.begin(), gaps.end(), 0);
    return 0;
}