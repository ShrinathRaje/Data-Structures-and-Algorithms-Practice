/* Queue ADT using circular array */
/* Date: 30th Apr 2019 */
/* Author: Shrinath Bhosale */

#include<stdio.h>
#include<stdlib.h>

typedef struct Queue Queue;

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void create(Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void display(Queue q) {
    if(q.front == q.rear)
        puts("queue is empty!");
    else {
        for(int i = q.front + 1; i != (q.rear + 1) % q.size; i = (i + 1) % q.size)
            printf("%i ", q.Q[i]);
    }

    puts("");
}

// time -> O(1)
void enqueue(Queue *q, int x) {
    if((q->rear + 1) % q->size == q->front)
        puts("queue is full!");
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear]  = x;
    }
}

// time -> O(1)
int dequeue(Queue *q) {
    int x = -1;

    if(q->rear == q->front)
        puts("queue is empty!");
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }

    return x;
}

int main(void) {
    Queue q;
    create(&q, 5);

    display(q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    display(q);

    enqueue(&q, 90);
    enqueue(&q, 100);

    display(q);

    printf("%i\n", dequeue(&q));
    printf("%i\n", dequeue(&q));
    return 0;
}