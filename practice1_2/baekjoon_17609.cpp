#include <iostream>
#include <vector>
using namespace std; 

//find a palindrome -> use two pointers
// pseudo palindrome -> make the helper function! 

bool isPalindrome(string& s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) return false; 
    }
    return true; 
}

int main() {
    int T; 
    cin >> T; 
    vector<string> list(T);
    for (int i = 0; i < T; i++) {
        cin >> list[i];
    }

    vector<int> ans; 
    for (string& s : list) {
        int left = 0, right = s.length() - 1; 
        bool isPseudo = false; 
        while (left < right) {
            if (s[left] != s[right]) { //palindrome won't fall into this if statement
                if (isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1)) {
                    ans.push_back(1); 
                } else {
                    ans.push_back(2);
                }
                isPseudo = true;  
                break;
            }
            left++; 
            right--; 
        }
        
        if (!isPseudo) ans.push_back(0); 
    }

    for (int& a : ans) {
        cout << a << endl;
    }
}