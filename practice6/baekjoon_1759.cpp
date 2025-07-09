#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;

bool isVowel(char& c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    return false;
}

void combinations(vector<char>& letters, string& temp, int idx, int vowelCnt) {
    
    if (temp.length() == L) { //exit condition
        if (vowelCnt >= 1 && vowelCnt < L-1) { 
            cout << temp << '\n'; 
        }
        return;
    }

    for (int i = idx; i < C; i++) {
        char letter = letters[i]; 
        temp.push_back(letter);
        if (isVowel(letter)) vowelCnt++;
        combinations(letters, temp, i + 1, vowelCnt);
        temp.pop_back();
        if (isVowel(letter)) vowelCnt--;
    }

    
}

int main() { 
    cin >> L >> C; 
    vector<char> letters(C);
    for (int i = 0; i < C; i++) {
        cin >> letters[i];
    }
    sort(letters.begin(), letters.end());

    string temp = "";
    combinations(letters, temp, 0, 0);
}  