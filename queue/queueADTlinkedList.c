/* Queue ADT using linked list */
/* Date: 30th Apr 2019 */
/* Author: Shrinath Bhosale */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x) {
    Node *t = (Node *)malloc(sizeof(Node));
    if(t == NULL)
        puts("queue is full");
    else {
        t->data = x;
        t->next = NULL;
        if(front == NULL) {
            front = rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue(void) {
    int x = -1;

    if(front == NULL)
        puts("queue is empty!");
    else {
        x = front->data;

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

void display(void) {
    if(front == NULL)
        puts("queue is empty!");
    else {
        Node *p = front;
        while(p) {
            printf("%i ", p->data);
            p = p->next;
        }

        puts("");
    }
}

int main(void) {
    display();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}