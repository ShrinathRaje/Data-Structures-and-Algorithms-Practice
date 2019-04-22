/* Sorted Insert In a Linked List */
/* Date: 22 Apr 2019 */
/* Author: Shrinath Bhosale */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node *next;
};

void display(Node *p) {
    while(p) {
        printf("%i\n", p->data);
        p = p->next;
    }

    puts("");
}

void sortedInsert(Node **head, int x) {
    Node *p = *head, *q = NULL;

    Node *t = (Node *)malloc(sizeof(Node));
    t->data = x;
    t->next = NULL;

    if (p == NULL)
        *head = t;
    else {
        while (p && p->data < x) {
            q = p;
            p = p->next;
        }

        if (p == *head) {
            t->next = *head;
            *head = t;
        }
        else {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main(void) {
    Node *head = NULL;

    display(head);

    sortedInsert(&head, 10);
    sortedInsert(&head, 20);
    sortedInsert(&head, 5);
    sortedInsert(&head, 2);
    sortedInsert(&head, 45);
    sortedInsert(&head, 41);

    display(head);
    
    return 0;
}