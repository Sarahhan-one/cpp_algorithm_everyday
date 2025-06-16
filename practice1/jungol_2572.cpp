#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std; 

// k consecutive dishes -> discounted 
// x coupon -> 1 x free dish or cook will make a new
// max the k
int main() {
    int N, d, k, c; 
    cin >> N >> d >> k >> c;
    vector<int> conveyor(N); 
    for (int i = 0; i < N; i++) {
        cin >> conveyor[i];
    }

    //1. can I eat k-close different consecutive dishes?
    //2. does it include coupon c? - add 1 or not
    

    int maxKinds = 0;
    for (int i = 0; i < N; i++) {
        unordered_set<int> kinds;
        for (int j = 0; j < k; j++) { //j should be a loop
            int idx = (i+j) % N;
            kinds.insert(conveyor[idx]);
        }

        // int kindSize = kinds.size() + (kinds.count(c) == 0 ? 1 : 0);
        if (kinds.find(c) == kinds.end()) {
            kindSize++;
        }
        maxKinds = max(maxKinds, kindSize);

        if (maxKinds == k+1) break;
    }

    cout << maxKinds;
    return 0;

}  