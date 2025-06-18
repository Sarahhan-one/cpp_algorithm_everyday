#include <iostream>
#include <algorithm>
using namespace std; 

//1. add A from the back 
//2. flip the array and add B from the back
int main() {
    string input, target; 
    cin >> input >> target;

    // int ans = 0; 
    while(input.length() < target.length()) {
        if (target.back() == 'A') {
            target.pop_back();
        } 
        else if (target.back() == 'B') {
            target.pop_back();
            reverse(target.begin(), target.end());
        } 
    }

    if (input == target) cout << 1;
    else cout << 0; 
    
}