#include <iostream>
#include <vector>
#include <set>
using namespace std; 

//2 3 2 3 1 2 7 
//it is best to pull out the one unused/ used at the latest
//case 1. device is already plugged -> do nothing 
//case 2. there's a hole left -> plug it 
//case 3. all holes are used 
//  -> for plugged devices, check when it'll be used again
//  -> choose the one unused/ used at the latest

//use set<int> for extension cord to avoid possible duplicates

int main() {
    int N, K; 
    cin >> N >> K;
    vector<int> devices(K);
    for (int i = 0; i < K; i++) {
        cin >> devices[i];
    }

    int unplug = 0; //ans
    set<int> extension;
    for (int i = 0; i < K; i++) {
        int device = devices[i];
        if (extension.find(device) != extension.end()) continue; //case 1 

        if (extension.size() < N) { //case 2
            extension.insert(device);
            continue; 
        }
        
        //case 3 - find the fartest device on the device sequence 
        int fartestNextUse = -1;
        int toRemove = -1; 
        for (const int& plugged : extension) {
            int nextUse = K; //maxVal 
            for (int j = i+1; j < K; j++) {
                if (devices[j] == plugged) {
                    nextUse = j; 
                    break; 
                }
            }

            if (nextUse > fartestNextUse) {
                fartestNextUse = nextUse; 
                toRemove = plugged;
            }
        }
        extension.erase(toRemove);
        extension.insert(device);
        unplug++;
    }
    cout << unplug;
} 
  