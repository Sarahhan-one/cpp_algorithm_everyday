#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; 

// k consecutive dishes -> discounted 
// x coupon -> 1 x free dish or cook will make a new
// max the kinds
int main() {
    int N, d, k, c; 
    cin >> N >> d >> k >> c;
    vector<int> conveyor(N); 
    for (int i = 0; i < N; i++) {
        cin >> conveyor[i];
    }

    //use sliding window (size of k) - unordered_map<kinds, cnt> 
    int maxKinds = 0; //ans 
    unordered_map<int, int> freq; 

    //initialize the window
    int uniqueCnt = 0; 
    for (int i = 0; i < k; i++) {
        if (freq[conveyor[i]] == 0) {//if it's unique 
            uniqueCnt++; 
        }
        freq[conveyor[i]]++;
    }
    //initialize the maxKinds 
    maxKinds = uniqueCnt + (freq[c] == 0 ? 1 : 0);

    //slide the window
    //remove the leftmost element and add the rightmost element 
    for (int i = 1; i < N; i++) {
        //remove the leftmost element 
        int removeIdx = (i-1) % N; 
        freq[conveyor[removeIdx]]--; 
        if (freq[conveyor[removeIdx]] == 0) {
            uniqueCnt--; 
        }

        //add the rightmost element
        int addIdx = (i+k -1) % N; 
        if (freq[conveyor[addIdx]] == 0) {
            uniqueCnt++; 
        } 
        freq[conveyor[addIdx]]++; 
        
        int currentKinds = uniqueCnt + (freq[c] == 0 ? 1 : 0);
        maxKinds = max(maxKinds, currentKinds);

        if (maxKinds == k+1) break;
    }

    cout << maxKinds;

} 