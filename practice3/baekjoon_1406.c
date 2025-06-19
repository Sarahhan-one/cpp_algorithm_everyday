#include <stdio.h>
#include <stdlib.h>

#define max_char 600000
#define max_m 500000

typedef struct _pair {
    char first;
    char second; 
} pair_t; 

typedef struct _node {
    int data; 
    struct _node* prev; 
    struct _node* next;
} node_t;

typedef node_t* p_node; 

node_t* createNode(char value) {
    node_t* node = (node_t*)malloc(sizeof(node_t)); 
    if (node == NULL) {
        exit(1); 
    }
    node->data = value; 
    node->prev = NULL; 
    node->next = NULL; 
    return node; 
}

void appendNode(p_node tail, p_node newNode) {
	newNode->prev = tail->prev; 
	newNode->next = tail;
	tail->prev->next = newNode;
	tail->prev = newNode;
}

void printNode(p_node head, p_node tail) {
	for (p_node curr = head->next; curr != tail; curr = curr->next) {
		printf("%c", curr->data);
	}
}

int main() {
    char inputs[max_char] = {0};
    scanf("%s", &inputs);

    int M; 
    scanf("%d", &M);

    pair_t edits[max_m] = {0};
    for (int i = 0; i < M; i++) {
        char temp, temp2; 
        do {
            temp = getchar();
        } while (temp == '\n' || temp == ' ');
        edits[i].first = temp;
        edits[i].second = 0;

        if (temp == 'P') {
            do {
                temp2 = getchar();
            } while (temp2 == ' ');
        }
        edits[i].second = temp2;
    }  

    p_node head = createNode(0);
    p_node tail = createNode(0);
    head->next = tail; 
    tail->prev = head; 

    for (int i = 0; inputs[i] != 0; i++) { 
        appendNode(tail, createNode(inputs[i]));
    }

    p_node cursor = tail; 

    for (int i = 0; edits[i].first != 0; i++) {
        char command = edits[i].first; 
        switch (command) {
            case 'L' :
            {
                if (cursor->prev != head) cursor = cursor->prev; 
                break;
            }
            case 'D' :
            {
                if (cursor != tail) cursor = cursor->next;
                break;
            }
            case 'B' :
            {
                if (cursor->prev != head) {
                    p_node dNode = cursor->prev; 
                    dNode->prev->next = dNode->next;
                    dNode->next->prev = dNode->prev; 
                    free(dNode);
                }
                break; 
            }
            case 'P' : 
            {
                p_node newNode = createNode(edits[i].second);
                newNode->prev = cursor->prev;
                newNode->next = cursor; 
                cursor->prev->next = newNode;
                cursor->prev = newNode;
            }
            break;
        }
    }

    printNode(head, tail);

}