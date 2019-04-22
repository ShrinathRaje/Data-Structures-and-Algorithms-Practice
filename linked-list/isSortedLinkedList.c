/* checking if a linked list is sorted */
/* Date: 22 Apr 2019 */
/* Author: Shrinath Bhosale */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* create(int A[], int n) {
    int i;
    struct Node *t, *last;
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

    return first;
}

void display(struct Node *p) {
    while(p) {
        printf("%i ", p->data);
        p = p->next;
    }
    puts("");
}

int isSorted(struct Node *p) {
    int min = p->data;
    p = p->next;

    while(p) {
        if(p->data < min)
            return 0;

        min = p->data;
        p = p->next;
    }

    return 1;
}

int main() {
    int A[] = {3, 5, 7, 10, 25, 32};
    struct Node *first = create(A, 6);

    printf("%i\n", isSorted(first));
    
return 0;
}