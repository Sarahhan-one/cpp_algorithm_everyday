#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

//0 : 0 // 1 0 
//1 : 1 // 0 1 
//2 : 1 + 0 // 0 1 + 1 0 = 1 1 
//3 : 2 + 1 // 1 1 + 0 1 = 1 2 

int main() {
    int N; 
    cin >> N; 
    vector<int> inputs(N); 
    for (int i = 0; i < N; i++) {
        cin >> inputs[i];
    }  

    int maxElement = *max_element(inputs.begin(), inputs.end());

    vector<int> cntZeros(maxElement+1);
    vector<int> cntOnes(maxElement+1); 

    //base values
    cntZeros[0] = 1; 
    cntZeros[1] = 0; 
    cntOnes[0] = 0;
    cntOnes[1] = 1;

    for (int i = 2; i <= maxElement; i++) {
        cntZeros[i] = cntZeros[i-1] + cntZeros[i-2]; 
        cntOnes[i] = cntOnes[i-1] + cntOnes[i-2];
    }

    for (int& input : inputs) {
        cout << cntZeros[input] << " " << cntOnes[input] << endl;
    }
    return 0;
}