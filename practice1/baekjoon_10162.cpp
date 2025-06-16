#include <iostream>
using namespace std; 

// A = 5min = 300s, B = 1min = 60s, C = 10s 
// while time is greater than A -> subtract A ...
int main() {
    int time; 
    cin >> time; 

    int cntA = 0, cntB = 0, cntC = 0; 
    while (time >= 300) {time -= 300; cntA++;}
    while (time >= 60) {time -= 60; cntB++;}
    while (time >= 10) {time -= 10; cntC++;}

    if (time) cout << -1; 
    else printf("%d %d %d", cntA, cntB, cntC);
}