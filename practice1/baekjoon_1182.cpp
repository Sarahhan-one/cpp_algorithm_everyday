#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S; 

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    int total = pow(2, N);

    for (int i = 1; i < total; i++) {
        vector<int> bitMap(N);
        for (int j = 0; j < N; j++) {
            bitMap[j] = (i >> j) & 1;
        }
        if (S == inner_product(arr.begin(), arr.end(), bitMap.begin(), 0)) cnt++;
    }
    cout << cnt;
}