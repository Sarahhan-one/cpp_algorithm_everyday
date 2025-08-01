#include <iostream>
#include <vector>
using namespace std; 

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int length = 0;
    int start = 0; 
    int end = length;

    while (length < N) {
        while (end < N) {
            int sum = 0;
            int start_copy = start;
            while (start_copy <= end) {
                sum += nums[start_copy];
                start_copy++;
            }

            if (length == 0) sum -= nums[start];

            if (sum >= M) { 
                cout << length+1 << endl; 
                return 0; 
            }
            start++; 
            end++;
        }

        length++; 
        start = 0; 
        end = length;
        // cout << start << " " << end <<  " " << length << endl;
    }

    cout << 0;
    return 0;
}