#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std; 

int main() {
    int num; 
    cin >> num; 
    vector<int> cont(num);
    for (int i = 0; i < num; i++) {
        cin >> cont[i];
    }

    sort(cont.begin(), cont.end()); 

    for (auto& c : cont) {
        cout << c <<'\n';
    }
}