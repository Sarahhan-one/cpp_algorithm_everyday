#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int cnt = 0;
void dfs(string temp, int idx, int& totalLength, unordered_map<char, int>& mp) {
    if (idx == totalLength) { cnt++; return; } //exit condition 

    for (auto i = mp.begin(); i != mp.end(); i++) {
        char key = i->first; 
        int value = i->second;

        if (temp[idx-1] == key) continue;
        if (value == 0) continue;

        temp.push_back(key);
        mp[key]--;
        dfs(temp, idx+1, totalLength, mp);
        mp[key]++;
        temp.pop_back();

    }
}

int main() {
    string str;
    cin >> str;

    unordered_map<char, int> mp;
    int totalLength = 0;
    for (char c : str) {
        mp[c]++;
        totalLength++;
    }

    string temp = {};
    dfs(temp, 0, totalLength, mp);

    cout << cnt;
}