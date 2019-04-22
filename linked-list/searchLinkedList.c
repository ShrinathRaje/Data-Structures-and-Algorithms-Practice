/* Searching in a linked list */
/* Date: 22th Apr 2019 */
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

struct Node* search(struct Node **head, int key) {
    struct Node *p = *head, *q = NULL;
    while(p) {
        if(key == p->data) {
            //improving the linear search by moving the found node to the front
            if(q) {
                q->next = p->next;
                p->next = *head;
                *head = p;
            }

            return p;
        }

        q = p;
        p = p->next;
        
    }

    return NULL;
}

//recursive method, time -> O(n), space -> O(n)
struct Node* Rsearch(struct Node *p, int key) {
    if(!p)
        return NULL;

    if(key == p->data)
        return p;

    return Rsearch(p->next, key);
}

int main() {
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    struct Node *first = create(A, 8);

    struct Node *r = search(&first, 32);
    if(r)
        printf("key found: %i\n", r->data);
    else {
        printf("key not found\n");
    }

    display(first);

    printf("%p\n", Rsearch(first, 11));
    
return 0;
}