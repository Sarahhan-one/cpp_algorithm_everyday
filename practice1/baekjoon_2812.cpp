#include <iostream>
#include <vector>
#include <algorithm>
#include <map> 
using namespace std; 

//from the front, track the 'numDel' of smallest number index
//save the next index if it's smaller than the max of container -> use set
//erase them at the end

//192 -> delete 12 
//123 -> delete 12 
// if the listDel is full and the next element is bigger, return the value
int main() {
    int len, numDel; 
    cin >> len >> numDel; 
    string nums;
    cin >> nums;
    
    vector<char> ans; 
    for (int i = 0; i < len; i++) {
        char num = nums[i];

        while (!ans.empty() && numDel > 0 && ans.back() < num) {
            ans.pop_back();
            numDel--;
        }
        ans.push_back(num);
    }

    while (numDel > 0) {
        ans.pop_back();
        numDel--;
    }

        // if (listDel.size() < numDel) {
        //     listDel[num] = i;
        // }
        // else if (num < listDel.rbegin()->first) { //listDel.size() >= numDel
        //     listDel.erase(listDel.rbegin()); 
        //     listDel[num] = i;
        // }
        // else {
        //     break;
        // }

    for (auto& c : ans){
        cout << c; 
    }
}