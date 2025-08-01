#include <iostream>
#include <vector>
#include <string>
using namespace std; 

int main() { 
    int N; 
    cin >> N; 


    int ans = 0;

    while (N--) {
        string word; 
        cin >> word;

        vector<int> alphabets(26); //alphabet | cnt
        bool isGroup = true;
        for (int i = 0; i < word.length(); i++) {
            int prev_c; 
            int c = word[i] - 'a';

            if (i == 0) {
                prev_c = c;
                alphabets[c]++;
                continue;
            }

            if (c == prev_c) continue;

            if (alphabets[c] != 0) isGroup = false;

            alphabets[c]++;
            prev_c = c;
        }

        if (isGroup) ans++;
    }


    cout << ans;
}