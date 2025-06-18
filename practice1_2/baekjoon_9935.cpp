#include <iostream>


using namespace std; 
int main() {
    string str, key; 
    cin >> str >> key;

    //use substr() to check if keyWord is made with a new character 
    //if we find, erase() 
    string temp; 
    for (const char& c : str) {
        temp.push_back(c); 
        if (temp.size() >= key.size() && temp.substr(temp.size() - key.size(),key.size()) == key) {
            temp.erase(temp.end() - key.size(), temp.end()); 
        }
    }

    if (temp.empty()) cout << "FRULA"; 
    else cout << temp;
}