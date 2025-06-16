#include <iostream>
#include <vector>
#include <string>
using namespace std; 

int main() {
    int N;
    cin >> N;
    
    int cnt = 0;
    
    for (int i = 1; i <= N; i++) {
        string num = to_string(i);
        
        if (num.length() == 1) {
            cnt++;
            continue;
        }
        
        vector<int> digits;
        for (char c : num) {
            digits.push_back(c - '0');
        }

        int d = digits[1] - digits[0];
        bool isArithmetic = true;
        
        for (int j = 2; j < digits.size(); j++) {
            if (digits[j] - digits[j-1] != d) {
                isArithmetic = false;
                break;
            }
        }
        
        if (isArithmetic) {
            cnt++;
        }
    }
    
    cout << cnt;
}