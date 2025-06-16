#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

//1. hop_past <= hop < hop_past
//2. only hop to the right 
//3. only hop twice
//frog can start at any point 

//find the all possabilities that satifies the conditions

//1 3 4 7 10
int main() {
    int N; 
    vector<int> leaves(N); 
    cin >> N; 
    for (int i = 0; i < N; i++) {
        int leaf; 
        cin >> leaf; 
        leaves.push_back(leaf);
    }

    sort(leaves.begin(), leaves.end());

    vector<vector<int>> res;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int first = leaves[i];
        for (int j = i+1; j < N; j++) {
            int second = leaves[j]; 
            for (int k = j+1; k < N; k++) {
                int third = leaves[k];

                if ((2*(second-first) >= third-second) && (second - first <= third - second)) {
                    // cout << first << " " << second << " " << third << endl;
                    ans++; 
                }
            }
        }
    }
    cout << ans;
    
}