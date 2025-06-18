#include <iostream>
#include <queue> 
using namespace std; 

//sort the list in the ascending order and do A+B comparison
int main() {
    int num, temp;
    cin >> num; 
    priority_queue<int, vector<int>, greater<int>> list; 
    for (int i = 0; i < num; i++) {
        cin >> temp;
        list.push(temp); 
    }

    int res = 0;
    while (list.size() >= 2) {
        int first = list.top();
        list.pop();
        int second = list.top(); 
        list.pop(); 

        list.push(first+second);
        res += first+second; 
    }

    cout << res;
}