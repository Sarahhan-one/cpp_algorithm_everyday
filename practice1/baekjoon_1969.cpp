#include <iostream> 
#include <vector>
#include <map>
using namespace std;

//compare the character on the same place
//pick the major one, save in on res string, and count the non-major ones
int main() {
    int num, len; 
    cin >> num >> len; 
    vector<string> dnaStr(num); 
    for (int i = 0; i < num; i++) {
        cin >> dnaStr[i]; 
    }
    

    string res = "";
    int cnt = 0; 
    for (int i = 0; i < len; i++) {
        map<char, int> nucleoMap;  
        for (string& dna : dnaStr) {
            char nucleo = dna[i];
            nucleoMap[nucleo]++;
        }
        
        int maxVal = 0; 
        string maxKey;
        for (auto& pair : nucleoMap) {
            if (pair.second > maxVal) {
                maxVal = pair.second; 
                maxKey = pair.first;
            }
        }
        cnt += num - maxVal;
        res += maxKey;
    }

    cout << res << '\n' << cnt;
}  