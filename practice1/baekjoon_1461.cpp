#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std; 

int main() { 
    int N, M;
    cin >> N >> M; 
    vector<int> shelves(N);
    for (int i = 0; i < N; i++) {
       cin >> shelves[i];
    }

    //-39 -37 -29 -28 -6 [0] 2 11 -> 11*2 + 6*2 + 29*2 + 39 : M = 2
    //-45 -26 -18 -9 - 4 [0] 22 40 50 -> 45*2 + 9*2 + 50
    //only the farthest trip is one-way, all others are round trips 
    //starts from the each sides's farthest, take the M steps inward each time 
    sort(shelves.begin(), shelves.end());

    vector<int> left, right; 
    for (const int& shelf : shelves) {
        if (shelf < 0) left.push_back(shelf);
        else right.push_back(shelf);
    }

    vector<int> dists;
    for (int i = 0; i < left.size(); i += M) {//start from the farthest
        dists.push_back(abs(left[i]));
    }
    for (int i = right.size() - 1; i >= 0; i -= M) {
        dists.push_back(right[i]);
    }

    int totalDist = 0;
    for (int dist : dists) {
        totalDist += 2*dist; 
    }

    //subtract the farthest return trip
    // totalDist -= max(abs(left.front()), right.back()); 
    totalDist -= *max_element(dists.begin(), dists.end());
    
    cout << totalDist;
}