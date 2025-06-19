#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define N_MAX 100
#define MAX_SIZE 100000
#define WALK_MAX INT_MAX

typedef struct _node {
    int r;
    int c;
    int walk;
} node;

int N;
int mount[N_MAX + 2][N_MAX + 2] = { 0 };
int walks[N_MAX + 2][N_MAX + 2];
int front, rear;
node Queue[MAX_SIZE] = { 0 };
int ans = WALK_MAX;

void enqueue(int r, int c, int walk) {
    Queue[rear] = (node){ r, c, walk };
    rear = (rear + 1) % MAX_SIZE;
}

node dequeue(void) {
    node temp =  Queue[front];
    front = (front + 1) % MAX_SIZE;
    return temp;
    
}

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

void BFS(int sr, int sc) {
    front = rear = 0;

    enqueue(sr, sc, 0);
    walks[sr][sc] = 0;

    while (front != rear) {
        node curN = dequeue();

        if (mount[curN.r][curN.c] == 0) {
            if (ans > curN.walk) {
                ans = curN.walk;
            }
            continue;
        }

        int nextR, nextC;
        for (int i = 0; i < 4; i++) {
            int curWalk = curN.walk;
            nextR = dr[i] + curN.r;
            nextC = dc[i] + curN.c;
            if (MIN(nextR, nextC) < 0 || MAX(nextR, nextC) >= N_MAX+2) continue;

            int dist = mount[curN.r][curN.c] - mount[nextR][nextC];
            if (dist < 0) curWalk -= dist;
            else if (dist > 0) curWalk += dist * dist;

            if (walks[nextR][nextC] <= curWalk) continue;
            
            walks[nextR][nextC] = curWalk;
            enqueue(nextR, nextC, curWalk);
        }
    }
}

int main() {
    int sr, sc;
    (void)scanf("%d %d %d", &N, &sr, &sc);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            (void)scanf("%d", mount[i] + j);
        }
    }

    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= N + 1; j++) {
            walks[i][j] = WALK_MAX;
        }
    }

    BFS(sr, sc);

    //printf("\n");
    //printf("\n");
    //for (int i = 0; i <= N + 1; i++) {
    //    for (int j = 0; j <= N + 1; j++) {
    //        printf("%d ", walks[i][j]);
    //    }
    //    printf("\n");
    //}

    printf("%d", ans);

    return 0;
}