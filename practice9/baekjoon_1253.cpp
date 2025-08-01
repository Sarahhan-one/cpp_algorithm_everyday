#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() {
    int N;
    cin >> N; 

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        int target = nums[i];
        int left = 0; 
        int right = N-1;

        while (left < right) {
            if (left == i) left++;
            else if (right == i) right--;

            int sum = nums[left] + nums[right];
            if (sum == target && left < right) { 
                cnt++; 
                // cout << left << " " << right << endl; 
                break; 
            }
            else if (sum < target) left++;
            else right--;
        }
    }

    cout << cnt;
}