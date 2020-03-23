//priority queue

#include<stdio.h>

//queue to hold 100 positive integers >= 0
int queue[100];
const int SIZE_OF_QUEUE = sizeof(queue) / sizeof(int);
int tail = -1;

//enqueue is O(log n) operation
void enqueue(int n) {
    if(tail == SIZE_OF_QUEUE - 1) {
        puts("Queue is full!");
        return;
    }

    queue[++tail] = n;

    int i = tail;

    while(i > 0 && queue[i] > queue[(i-1) / 2]) {
        int temp = queue[i];
        queue[i] = queue[(i-1) / 2];
        queue[(i-1) / 2] = temp;
        i = (i-1) / 2;
    }
}

//dequeue is O(log(n)) operation
int dequeue() {
    if(tail == -1) {
        puts("Queue is empty!");
        return -1;
    }

    int last_index = tail--;
    int temp = queue[0];
    queue[0] = queue[last_index];

    int i = 0;
    int j = 2*i + 1;
    while(j < last_index - 1) {
        if(j < last_index-1 && queue[j+1] > queue[j])
            ++j;

        if(queue[i] < queue[j]) {
            int t = queue[i];
            queue[i] = queue[j];
            queue[j] = t;
            i = j;
            j = 2*j + 1;
        } else {
            break;
        }
    }

    return temp;
}

void print_queue() {
    putchar('\n');

    for(int i=0; i<=tail; ++i) {
        printf("%i ", queue[i]);
    }

    putchar('\n');
}

int main(void) {

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);

    print_queue();

    //highest priority elements are dequeued first
    printf("%i\n", dequeue());
    printf("%i\n", dequeue());
    printf("%i\n", dequeue());
    printf("%i\n", dequeue());
    printf("%i\n", dequeue());
    printf("%i\n", dequeue());
    printf("%i\n", dequeue());
    printf("%i\n", dequeue());

    print_queue();

    return 0;
}