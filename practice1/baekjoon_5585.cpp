#include <iostream> 
using namespace std; 

// pay with 1000 bill 
// change : 500, 100, 50, 10, 5, 1 
int main() {
    int cost;
    cin >> cost; 

    int change = 1000 - cost; 
    int cnt = 0; 
    int coins[] = {500, 100, 50, 10, 5, 1};

    for (int coin : coins) {
        cnt += change / coin; 
        change %= coin; 
    }

    cout << cnt;
}