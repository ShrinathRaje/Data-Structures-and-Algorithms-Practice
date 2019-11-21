/*
* Iterative tree traversals
* Date: 21st Nov 2019
* Author: Shrinath Bhosale
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct QueueNode QueueNode;
typedef struct StackNode StackNode;
typedef struct BSTNode BSTNode;

struct QueueNode {
    BSTNode *addr;
    QueueNode *next;
} *front = NULL, *rear = NULL;

struct StackNode {
	BSTNode *addr;
	StackNode *next;
};

struct BSTNode {
    int data;
    BSTNode *left;
    BSTNode *right;
};

int isQueueEmpty(void) {
    return (front == NULL) ? 1 : 0;
}

void enqueue(BSTNode *x) {
    QueueNode *t = (QueueNode *)malloc(sizeof(QueueNode));
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
            QueueNode *temp = front;
            front = front->next;
            free(temp);
        }
    }

    return x;
}

//stack operations
void push(BSTNode *addr, StackNode **top) {
	StackNode *n = malloc(sizeof(StackNode));
	n->addr = addr;
	n->next = *top;
	*top = n;
}

BSTNode* pop(StackNode **top) {
	if(*top == NULL)
		return NULL;
		
	StackNode *temp = *top;
	BSTNode *addr = (*top)->addr;
	*top = (*top)->next;
	free(temp);
	
	return addr;
}

int isStackEmpty(StackNode *top) {
	return (top) ? 0 : 1;
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

void iterativePreOrderTraversal(BSTNode *p) {
	StackNode *top = NULL;
  	while(p != NULL || !isStackEmpty(top)) {
  		if(p != NULL) {
  			printf("%i ", p->data);
  			push(p, &top);
  			p = p->left;
  		} else {
  			BSTNode *n = pop(&top);
  			p = n->right;
  		}
  	}		
}

void iterativeInOrderTraversal(BSTNode *p) {
    StackNode *top = NULL;
  	while(p != NULL || !isStackEmpty(top)) {
  		if(p != NULL) {
  			push(p, &top);
  			p = p->left;
  		} else {
  			BSTNode *n = pop(&top);
  			printf("%i ", n->data);
  			p = n->right;
  		}
  	}
}



int main(void) {
    BSTNode *root = createBinaryTree();

	iterativePreOrderTraversal(root);
	putchar('\n');
	
	iterativeInOrderTraversal(root);
	putchar('\n');

    return 0;
}
