#include <iostream>
#include <queue> 
using namespace std;

int main() {
    //for faster I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N; 

    priority_queue<int, vector<int>, greater<int>> upperHalf; //min-heap for the upper half
    priority_queue<int> lowerHalf; //max-heap for the lower half

    for (int i = 0; i < N; i++) {
        int newNum; 
        cin >> newNum; 

        //inserting the new number
        if (lowerHalf.empty() || newNum <= lowerHalf.top()) {
            lowerHalf.push(newNum); 
        } else {
            upperHalf.push(newNum); 
        }

        //balancing check
        if (lowerHalf.size() > upperHalf.size()+1) { //unbalanced
            upperHalf.push(lowerHalf.top());
            lowerHalf.pop();
        } else if (upperHalf.size() > lowerHalf.size()) {
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }

        //priting the medium
        cout << lowerHalf.top() << "\n"; 
    }
}