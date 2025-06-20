#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define HEAP_SIZE (MAX * MAX)

typedef struct {
    int cost;
    int y;
    int x;
} Node;

typedef struct {
    Node arr[HEAP_SIZE];
    int size; //number of elements
} MinHeap;

void swap(Node* a, Node* b) {
    Node tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(MinHeap* h, int cost, int y, int x) {
    int i = ++(h->size);
    h->arr[i] = (Node){cost, y, x}; //create new node 

    while (i > 1 && h->arr[i].cost < h->arr[i / 2].cost) { //compare with parents node
        swap(&h->arr[i], &h->arr[i / 2]); //swap it if the new node is smaller
        i /= 2;
    }
}

Node pop(MinHeap* h) {
    Node ret = h->arr[1]; //pop the first one (minimum one)
    h->arr[1] = h->arr[h->size--]; //replace that place with the last element

    int parent = 1;
    while (1) {
        int left = parent * 2;
        int right = parent * 2 + 1;
        int smallest = parent;

        if (left <= h->size && h->arr[left].cost < h->arr[smallest].cost)
            smallest = left;
        else if (right <= h->size && h->arr[right].cost < h->arr[smallest].cost)
            smallest = right;

        if (smallest == parent) break;

        swap(&h->arr[parent], &h->arr[smallest]); //reorder the minHeap
        parent = smallest;
    }
    return ret;
}

int empty(MinHeap* h) {
    return h->size == 0;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int N, dest_y, dest_x;
    scanf("%d", &N);
    scanf("%d %d", &dest_y, &dest_x);
    dest_y--, dest_x--; // 0-indexed

    int height[MAX][MAX];
    int cost[MAX][MAX];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &height[i][j]);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cost[i][j] = INT_MAX;

    MinHeap heap = { .size = 0 };

    // edges 
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (y == 0 || y == N - 1 || x == 0 || x == N - 1) {
                int init_cost = height[y][x] * height[y][x];
                if (cost[y][x] > init_cost) {
                    cost[y][x] = init_cost;
                    push(&heap, init_cost, y, x);
                }
            }
        }
    }

    while (!empty(&heap)) {
        Node cur = pop(&heap);
        int y = cur.y, x = cur.x;
        int cur_cost = cur.cost;

        if (cur_cost > cost[y][x]) continue;

        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            int diff = height[ny][nx] - height[y][x];
            int move_cost = 0;
            if (diff > 0) move_cost = diff * diff;
            else if (diff < 0) move_cost = -diff;

            int new_cost = cur_cost + move_cost;
            if (new_cost < cost[ny][nx]) {
                cost[ny][nx] = new_cost;
                push(&heap, new_cost, ny, nx);
            }
        }
    }

    if (cost[dest_y][dest_x] == INT_MAX)
        printf("-1\n");  
    else
        printf("%d\n", cost[dest_y][dest_x]);

    return 0;
}
