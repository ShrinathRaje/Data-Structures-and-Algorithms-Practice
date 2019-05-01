/* Implementing Binary Tree using Queue */
/* Date: 1st May 2019 */
/* Author: Shrinath Bhosale */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
typedef struct BSTNode BSTNode;

struct Node {
    BSTNode *addr;
    Node *next;
} *front = NULL, *rear = NULL;

struct BSTNode {
    int data;
    BSTNode *left;
    BSTNode *right;
};

int isQueueEmpty(void) {
    return (front == NULL) ? 1 : 0;
}

void enqueue(BSTNode *x) {
    Node *t = (Node *)malloc(sizeof(Node));
    if(t == NULL)
        puts("queue is full");
    else {
        t->addr = x;
        t->next = NULL;
        if(front == NULL) {
            front = rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }
}

BSTNode* dequeue(void) {
    BSTNode *x = NULL;

    if(isQueueEmpty())
        puts("queue is empty!");
    else {
        x = front->addr;

        if(front == rear) {
            free(front);
            front = rear = NULL;
        } else {
            Node *temp = front;
            front = front->next;
            free(temp);
        }
    }

    return x;
}

void createNewNode(int x, BSTNode *b, char c) {
    BSTNode *t = (BSTNode *)malloc(sizeof(BSTNode));
    t->data = x;
    t->left = t->right = NULL;

    if(c == 'l')
        b->left = t;
    else if(c == 'r')
        b->right = t;

    enqueue(t);
}

BSTNode* createBinaryTree(void) {
    BSTNode *root = (BSTNode *)malloc(sizeof(BSTNode));
    printf("enter the root value: ");
    scanf("%i", &root->data);
    root->left = root->right = NULL;
    enqueue(root);

    while(!isQueueEmpty()) {
        int x;
        BSTNode *b = dequeue();
        printf("enter the left child of %i: ", b->data);
        scanf("%i", &x);

        if(x != -1)
            createNewNode(x, b, 'l');

        printf("enter the right child of %i: ", b->data);
        scanf("%i", &x);

        if(x != -1)
            createNewNode(x, b, 'r');
    }

    return root;
}

void preOrderTraversal(BSTNode *p) {
    if(p) {
        printf("%i ", p->data);
        preOrderTraversal(p->left);
        preOrderTraversal(p->right);
    }
}

void inOrderTraversal(BSTNode *p) {
    if(p) {
        preOrderTraversal(p->left);
        printf("%i ", p->data);
        preOrderTraversal(p->right);
    }
}

void postOrderTraversal(BSTNode *p) {
    if(p) {
        preOrderTraversal(p->left);
        preOrderTraversal(p->right);
        printf("%i ", p->data);
    }
}

int main(void) {
    BSTNode *root = createBinaryTree();

    preOrderTraversal(root);
    puts("");
    inOrderTraversal(root);
    puts("");
    postOrderTraversal(root);
    puts("");

    return 0;
}