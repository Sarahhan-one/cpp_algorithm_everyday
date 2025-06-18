#include <iostream>
#include <vector>
#include <limits.h>
using namespace std; 

int N, M; //number of closets N, list size M
int ans = INT_MAX; 
vector<int> list;

void dfs(int moves, int i, int open1, int open2) {
    if (moves >= ans) return; //pruning
    if (i == M) {//exit condition
        ans = min(ans, moves);
        return; 
    }

    //case1 : it's already open closets
    if (list[i] == open1 || list[i] == open2) {
        dfs(moves, i+1, open1, open2); 
    }

    //case2 : we need to consider 2 open closets
    int move1 = abs(open1 - list[i]);
    int open1_n = list[i]; 
    dfs(moves + move1, i+1, open1_n, open2); 

    int move2 = abs(open2 - list[i]);
    int open2_n = list[i]; 
    dfs(moves + move2, i+1, open1, open2_n); 
}

int main() {
    cin >> N; 

    int open1, open2; 
    cin >> open1 >> open2;

    cin >> M; 
    list.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> list[i]; 
    }

    int moves = 0; 
    dfs(moves, 0, open1, open2);

    cout << ans; 
}