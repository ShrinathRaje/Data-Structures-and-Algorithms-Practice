/*
* Level order traversal
* Date: 22nd Nov 2019
* Author: Shrinath Bhosale
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct QueueNode QueueNode;
typedef struct BSTNode BSTNode;

struct QueueNode {
    BSTNode *addr;
    QueueNode *next;
};

struct BSTNode {
    int data;
    BSTNode *left;
    BSTNode *right;
};

int isQueueEmpty(QueueNode *front) {
    return (front == NULL) ? 1 : 0;
}

void enqueue(QueueNode **front, QueueNode **rear, BSTNode *x) {
    QueueNode *t = (QueueNode *)malloc(sizeof(QueueNode));
    if(t == NULL)
        puts("queue is full");
    else {
        t->addr = x;
        t->next = NULL;
        if(*front == NULL) {
            *front = *rear = t;
        } else {
            (*rear)->next = t;
            *rear = t;
        }
    }
}

BSTNode* dequeue(QueueNode **front, QueueNode **rear) {
    BSTNode *x = NULL;

    if(isQueueEmpty(*front))
        puts("queue is empty!");
    else {
        x = (*front)->addr;

        if(*front == *rear) {
            free(*front);
            *front = *rear = NULL;
        } else {
            QueueNode *temp = *front;
            *front = (*front)->next;
            free(temp);
        }
    }

    return x;
}

void createNewNode(int x, BSTNode *b, char c, QueueNode **front, QueueNode **rear) {
    BSTNode *t = (BSTNode *)malloc(sizeof(BSTNode));
    t->data = x;
    t->left = t->right = NULL;

    if(c == 'l')
        b->left = t;
    else if(c == 'r')
        b->right = t;

    enqueue(front, rear, t);
}

BSTNode* createBinaryTree(void) {
    QueueNode *front = NULL, *rear = NULL;
    BSTNode *root = (BSTNode *)malloc(sizeof(BSTNode));
    printf("enter the root value: ");
    scanf("%i", &root->data);
    root->left = root->right = NULL;
    enqueue(&front, &rear, root);

    while(!isQueueEmpty(front)) {
        int x;
        BSTNode *b = dequeue(&front, &rear);
        printf("enter the left child of %i: ", b->data);
        scanf("%i", &x);

        if(x != -1)
            createNewNode(x, b, 'l', &front, &rear);

        printf("enter the right child of %i: ", b->data);
        scanf("%i", &x);

        if(x != -1)
            createNewNode(x, b, 'r', &front, &rear);
    }

    return root;
}

void levelOrderTraversal(BSTNode *p) {
    if(!p)
        return;

    QueueNode *front = NULL, *rear = NULL;

    printf("%i ", p->data);
    enqueue(&front, &rear, p);

    while(!isQueueEmpty(front)) {
        BSTNode *t = dequeue(&front, &rear);

        if(t->left) {
            printf("%i ", t->left->data);
            enqueue(&front, &rear, t->left);
        }

        if(t->right) {
            printf("%i ", t->right->data);
            enqueue(&front, &rear, t->right);
        }
    }
}

int main(void) {
    BSTNode *root = createBinaryTree();

	levelOrderTraversal(root);
    putchar('\n');

    return 0;
}