/* Stack ADT using Linked List */
/* Date: 24th Apr 2019 */
/* Author: Shrinath Bhosale */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node *next;
};

int isEmpty(Node *top) {
    return (top == NULL) ? 1 : 0;
}

void display(Node *top) {
    if(isEmpty(top))
        puts("stack is empty!");
    else {
        Node *p = top;
        while(p){
            printf("%i ", p->data);
            p = p->next;
        }

       putchar('\n'); 
    }
}

// time -> O(1)
void push(Node **top, int key) {
    Node *t = (Node *)malloc(sizeof(Node));

    if(t == NULL)
        puts("stack is full!");
    else {
        t->data = key;
        t->next = *top;
        *top = t;
    }
}

// time -> O(1)
int pop(Node **top) {
    int x = -1;

    if(isEmpty(*top))
        puts("stack is empty!");
    else {
        Node *temp = *top;
        x = (*top)->data;
        *top = (*top)->next;
        free(temp);
    }

    return x;
}

int top(Node *top) {
    int x = -1;

    if(isEmpty(top))
        puts("stack is empty!");
    else {
        x = top->data;
    }

    return x;
}

int main(void) {
    Node *head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);

    display(head);

    pop(&head);

    display(head);

    printf("%i\n", top(head));
    
    return 0;
}