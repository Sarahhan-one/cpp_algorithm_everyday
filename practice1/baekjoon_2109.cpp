#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

//lecture within d days, p paid
//store it in unordered_map <d, max_p> -> don't work

// int main() {
//     int n, d, p;
//     cin >> n; 
//     unordered_map<int, int> lectures; 
//     for (int i = 0; i < n; i++) {
//         cin >> p >> d; 
//         if (lectures.find(d) == lectures.end()) {
//             lectures[d] = p; 
//             continue;
//         }
//         if (lectures[d] < p) {
//             lectures[d] = p; 
//         }
//     }

//     int ans = 0; 
//     for (const auto& lecture : lectures) {
//         ans += lecture.second;
//     }

//     cout << ans; 
// }

//need to pass the test case : 5, 100 3, 200 2, 50 2, 30 1, 20 1
// -> schedule the highest paying job earlier 
// pick the highest paying lecture first, and schedule it on the latest day within its deadline 
// use bool[] of size (max_deadline+1) to mark days used 

int main() {
    int n, max_d = 0;
    cin >> n; 
    vector<pair<int, int>> lectures(n); //{p , d}
    for (int i = 0; i < n; i++) {
        cin >> lectures[i].first >> lectures[i].second;
        max_d = max(max_d, lectures[i].second);
    }

    vector<bool> marking(max_d);
    sort(lectures.rbegin(), lectures.rend()); //sort by payment

    int ans = 0; 
    for (const auto& lecture : lectures) {
        for (int i = lecture.second; i>0; i--) {
            if (!marking[i]) {
                ans += lecture.first; 
                marking[i] = true; 
                break;
            }
        }

    }
    cout << ans;; 
}