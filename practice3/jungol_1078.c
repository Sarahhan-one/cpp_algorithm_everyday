//bfs logic
//insert the location(x, y) to the queue along with remaining time 

#include <stdio.h> 

#define MAX_N (100+2)
typedef struct _node {
    int r; 
    int c;
}node; 

int C, R;
int sc, sr;
int map[MAX_N][MAX_N];

node queue[MAX_N * MAX_N];
int front, rear; 
void enqueue(int r, int c) {
    queue[rear].r = r;
    queue[rear].c = c;
    rear++;
}


node dequeue() {  
    return queue[front++];
}

static void inputData() {
    char temp[MAX_N] = { 0 };
    (void)scanf("%d %d", &C, &R); 

    for (int i = 1; i <= R; i++) {
        (void)scanf("%s", temp+1); 
        int* pTmp = map[i];
        
        for (int j = 1; j <= C; j++) {
            pTmp[j] = temp[j] - '0';
        }
    }
    (void)scanf("%d %d", &sc, &sr);
}

//For debugging 
static void printMap() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <=C; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1}; 

int BFS() {
    node curr = { 0 };
    int nr, nc, time = 0;

    front = rear = 0;
    enqueue (sr, sc);
    map[sr][sc] = 3; 

    while(front != rear) {
        curr = dequeue();
        time = map[curr.r][curr.c]; 
        for (int i = 0; i < 4; i++) {
            nr = curr.r + dr[i];
            nc = curr.c + dc[i];

            //all maps are filled with 0, and even if it goes out the boundary it won't affect the results
            // -> don't check the out of boudnary
            if (map[nr][nc] == 1) {
                enqueue(nr, nc); 
                map[nr][nc] = time + 1; 
            }
        }
    }
    // printMap();
    return time;
}


int main() {
    // freopen("input.txt", "r", stdin);
    inputData();
    // printMap();
    printf("%d\n", BFS());

    int cnt = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <=C; j++) {
            if(map[i][j] == 1) cnt++; 
        }
        
    }
    printf("%d", cnt);
    
}