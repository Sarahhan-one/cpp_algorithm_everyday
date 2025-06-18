#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

#define MAX (25) 

int N, num; 
int grid[MAX][MAX]; 
int dx[4] = {0, 1, 0, -1}; // down, left, up, right
int dy[4] = {1, 0, -1, 0};

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b); // ascending order
}

void recursion(int x, int y, int* cnt) {
    grid[x][y] = -1; 
    (*cnt)++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i]; 
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // out of bounds
        if (grid[nx][ny] == 1) {
            recursion(nx, ny, cnt);
        }
    }
}

int main() { 
    scanf("%d", &N);
    memset(grid, -1, sizeof(grid)); // initialize to -1
    
    for (int i = 0; i < N; i++) {
        char row[N + 1]; 
        scanf("%s", row);
        for (int j = 0; j < N; j++) {
            grid[i][j] = row[j] - '0'; 
        }
    }

    int num = 0;
    int num_size = 0;
    int cnts[MAX * MAX] = {0}; 

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (grid[x][y] == 1) {
                int cnt = 0;
                num++; 
                recursion(x, y, &cnt);
                cnts[num_size++] = cnt; 
            }
        }
    }

    
    qsort(cnts, num_size, sizeof(cnts[0]), comp);
    printf("%d\n", num);
    for (int i = 0; i < num_size; i++) {
        printf("%d\n", cnts[i]);
    }
}