#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> nums(N);
    for (int i=0; i<N; i++) {
        cin >> nums[i];
    }  

    sort(nums.begin(), nums.end());

    int ans = INT_MAX;
    for (int start = 0; start < N-1; start++) {
        int end = start+1;
        while (end < N-1 && nums[end] - nums[start] < M) end++;
        if (nums[end] - nums[start] >= M) ans = min(ans, nums[end] - nums[start]);
        // cout << start << " " << end << " " << ans << endl;
    }

    cout << ans;
}