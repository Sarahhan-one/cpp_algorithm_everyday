#include <iostream> 
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


// method 1: choose the next shortest one
// method 2: choose the next one that ends early <= this one works! 
int main() {
    int num;
    cin >> num; 

    vector<pair<int, int>> schedules(num); 
    for (int i = 0; i < num; i++) {
        cin >> schedules[i].first >> schedules[i].second;
    }


    //sorts by end time 
    sort(schedules.begin(), schedules.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    int start = -1, end = 0; 
    int cnt = 0;
    for (auto schedule : schedules) {
        if (end <= schedule.first) {
            start = schedule.first;
            end = schedule.second; 
            cnt++; 
        }
    }
    cout << cnt;
} 