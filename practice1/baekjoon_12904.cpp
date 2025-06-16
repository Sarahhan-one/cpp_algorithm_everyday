#include <iostream>
#include <limits.h>
using namespace std; 

//1. add A from the back 
//2. flip the array and add B from the back

bool found = false;
int cnt = INT_MAX; 

string taskOne (string input) {
    input += "A"; 
    return input; 
}

string taskTwo (string input) {
    input = string(input.rbegin(), input.rend());
    input += "B"; 
    return input; 
}

void dfs(string input, const string& target, int inc) {
    if (input.length() > target.length()) return;
    if (input == target) {
        found = true; 
        cnt = min(cnt, inc);
        return; 
    }

    dfs(taskOne(input), target, inc + 1); 
    dfs(taskTwo(input), target, inc + 1);
}

int main() {
    string input, target; 
    cin >> input >> target;
    
    dfs(input, target, 0);

    if (found) cout << cnt;
    else cout << -1;
}