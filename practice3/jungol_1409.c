#include <stdio.h>
#include <math.h> 
#include <limits.h>

int N, M; //number of closets N, list size M
int ans = INT_MAX; 
int list[21];

void dfs(int moves, int i, int open1, int open2) {
    if (moves >= ans) return; //pruning
    if (i == M) {//exit condition
        ans = moves;
        return; 
    }

    //case1 : it's already open closets - case2 includes this case
    // if (list[i] == open1 || list[i] == open2) {
    //     dfs(moves, i+1, open1, open2); 
    // }

    //case2 : we need to consider 2 open closets
    dfs(moves + abs(open1 - list[i]), i+1, list[i], open2); 
    dfs(moves + abs(open2 - list[i]), i+1, open1, list[i]); 
}

int main() {
    int open1, open2; 
    scanf("%d %d %d %d ", &N, &open1, &open2, &M); 
    
    for (int i = 0; i < M; i++) {
        scanf("%d ", &list[i]); 
    }

    dfs(0, 0, open1, open2);
    printf("%d", ans); 
}