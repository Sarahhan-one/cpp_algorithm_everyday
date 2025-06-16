#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std; 

//arrange the numbers to form the biggest number 
//take it as string, use the comparator s1 + s2 > s2 + s1
int main() {
    int n; 
    cin >> n;
    vector<string> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    sort(list.begin(), list.end(), 
        [](const string& a, const string& b) {
        return (a + b) > (b + a);
    }); 

    //special case where all numbers are zeros
    if (list.front() == "0") {
        cout << "0"; 
        return 0;
    }

    //put them together
    string ans = "";
    for (string& l : list) {
        ans += l; 
    }

    cout << ans;
    return 0;
}