#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

// bool binarySearch(vector<int>& nums, int target) {
//     int start = 0; 
//     int end = nums.size() - 1;

//     while (start <= end) {
//         int mid = start + (end - start)/2;

//         if (nums[mid] < target) start = mid+1;
//         else if (nums[mid] > target) end = mid-1;
//         else return 1; 
//     }
//     return 0;
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M; 
    cin >> N; 
    
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    // for (int i = 0; i < N; i++) {
    //     cout << i << " : " << nums[i] << endl;
    // }

    sort(nums.begin(), nums.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;
        cout << (binary_search(nums.begin(), nums.end(), target) ? 1 : 0) << '\n';
    }
    return 0;
}