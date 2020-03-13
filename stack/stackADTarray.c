/* Stack ADT using Array */
/* Date: 24th Apr 2019 */
/* Author: Shrinath Bhosale */

#include<stdio.h>
#include<stdlib.h>

typedef struct Stack Stack;

struct Stack {
    int size;
    int top;
    int *S;
};

void create(Stack *st) {
    printf("enter the size of a stack: ");
    scanf("%i", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

int isEmpty(Stack st) {
    return (st.top == -1) ? 1 : 0;
}

int isFull(Stack st) {
    return (st.top == (st.size - 1)) ? 1 : 0;
}

void display(Stack st) {
    if(isEmpty(st))
        puts("stack is empty!");
    else {
        for(int i = st.top; i >= 0; --i) {
            printf("%i ", st.S[i]);
        }
        putchar('\n');
    }
}

// time -> O(1)
void push(Stack *st, int key) {
    if(isFull(*st))
        puts("stack is full!");
    else {
        ++st->top;
        st->S[st->top] = key;
    }
}

//time -> O(1)
int pop(Stack *st) {
    int x = -1;

    if(isEmpty(*st)) {
        puts("stack is empty");
    } else {
        x = st->S[st->top--];
    }

    return x;
}

//time -> O(1)
int peek(Stack st, int index) {
    int x = -1;

    if(index < 1 || index > st.top + 1)
        puts("invalid index!");
    else {
        x = st.S[st.top - index + 1];
    }

    return x;
}

int top(Stack st) {
    int x = -1;

    if(isEmpty(st))
        puts("stack is empty");
    else {
        x = st.S[st.top];
    }

    return x;
}

int main(void) {
    Stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    display(st);

    pop(&st);
    pop(&st);

    display(st);

    printf("%i\n", peek(st, 1));
    printf("%i\n", peek(st, 2));
    printf("%i\n", peek(st, 3));
    printf("%i\n", top(st));
        
    return 0;
}
