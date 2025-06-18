#include <iostream>
#include <vector> 
using namespace std; 

int main() {
    int N; 
    cin >> N; 

    vector<int> deck; 
    if (N % 2) {
        for (int i = 0; i <= N; i += 2) {
            deck.push_back(i); 
        }
    } else {
        for (int i = 2; i <= N; i += 2) {
            deck.push_back(i);
        }
    }

    while (deck.size() > 1) {
        deck.erase(deck.begin());
        int card = deck.front();
        deck.erase(deck.begin());
        deck.push_back(card);
    }



    cout << deck.back();
}