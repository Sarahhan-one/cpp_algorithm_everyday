#include <stdio.h>
#include <limits.h>
#define MAX_N (13+1)
int N;                   
int arr[MAX_N][MAX_N];        
int vis[MAX_N];     
int cnt;      
int ans = INT_MAX;    

static void inputData() {
    (void)scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            (void)scanf("%d", &arr[i][j]);
        }
    }
}

// 디버깅 용도
static void printArr() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dfs (int cnt, int curr, int cost) {
    
    if (cost >= ans) return;
    cnt++;
    if (cnt == N) {
        int temp = arr[curr][1];
        if (temp == 0) return; 
        if (cost + temp < ans) {
            ans = cost + temp; 
        }
        return;
    }

    for (int i = 2; i <= N; i++) {
        if (vis[i] || arr[curr][i] == 0) continue; 
        
        vis[i] = 1; 
        dfs(cnt+1, i, cost + arr[curr][i]); 
        vis[i] = 0;
    }
}

void main() {
    // (void)freopen("input.txt", "r", stdin);
    inputData();
    // printArr();
    vis[1] = 1;
    dfs(1, 1, 0);
    printf("%d\n", ans);
    printf("call_cnt: %d\n", cnt);
}
