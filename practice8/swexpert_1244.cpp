#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int maxCnt;
int ans = 0;

void backtracking(string& numbers, int cnt) {
    if (cnt == maxCnt) { //exit condition
        ans = max(ans, stoi(numbers));
        return;
    }

    int temp;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size(); j++) {
            if (i == j) continue;

            temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
            backtracking(numbers, cnt+1);
            temp = numbers[j];
            numbers[j] = numbers[i];
            numbers[i] = temp;
        }
    }
}

int main() {
    int N;
    cin >> N;
    string numbers; 

    for (int i = 1; i <= N; i++) {
        cin >> numbers >> maxCnt;
        ans = 0;
        if (maxCnt - 5 > 0) {
            if (maxCnt % 2) maxCnt = 5;
            else maxCnt = 4;
        }
        backtracking(numbers, 0);
        cout << "#" << i << ' ' << ans << '\n';
    }
}