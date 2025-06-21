#include <iostream> 
#include <queue> 
using namespace std;

//FAIL : TIME-OUT
int main() {
    int N; 
    cin >> N;

    int temp;
    priority_queue<int, vector<int>, greater<int>> pq; 
    for (int i = 0; i < N; i++) {
        cin >> temp; 
        pq.push(temp);

        priority_queue<int, vector<int>, greater<int>> pq_copy = pq;
        if (pq.size() % 2) {//if the size is odd
            int idx = pq.size() / 2; 
            
            for (int j = 0; j < idx; j++) {
                pq_copy.pop(); 
            }
            cout << pq_copy.top();
        } 
        else { //if the size is even
            int idx = pq.size() / 3;

            for (int j = 0; j < idx; j++) {
                pq_copy.pop();
            }
            int temp1 = pq_copy.top();
            pq_copy.pop();
            int temp2 = pq_copy.top();
            cout << ((temp1 < temp2) ? temp1 : temp2);
        }
    }
}