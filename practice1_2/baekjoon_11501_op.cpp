#include <iostream>
#include <vector>
using namespace std; 

//option2 : traverse from end 
//if you find local max, profit = local max - current price
int main() {
    int N, num; 
    cin >> N; 

    while (N--) {
        cin >> num; 
        vector<int> stocks(num); 
        for (int i = 0; i < num; i++) {
            cin >> stocks[i];
        }

        int localMax = 0;
        long long profit = 0;
        for (int i = num-1; i >= 0; i--) {
            if (stocks[i] > localMax) {
                localMax = stocks[i];
            }
            profit += (long long)localMax - stocks[i];
        }

        cout << profit << '\n';
    }
}