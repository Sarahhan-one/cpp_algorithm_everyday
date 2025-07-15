#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int input; 
    cin >> input; 

    string nums;
    nums = to_string(input);   

    vector<int> cnt(9);
    for (int i = 0; i < nums.length(); i++) {
        int idx = (nums[i]) - '0';
        if (idx == 9) idx = 6;
        cnt[idx]++; 
        // cout << nums[i] << endl;
    }
    
    int maxCnt = 0;
    for (int i = 0; i < 9; i++) {
        if (i == 6) {
            maxCnt = max(maxCnt, (cnt[i]+1) / 2);
        }
        else { maxCnt = max(maxCnt, cnt[i]); }

        // cout << i << " " << cnt[i] << endl;
    }

    cout << maxCnt;

} 