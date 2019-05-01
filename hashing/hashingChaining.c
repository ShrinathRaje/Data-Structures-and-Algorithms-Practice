/* Hashing | Collision resolution using chaining */
/* Date: 1st May 2019 */
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
        printf("%i ", p->data);
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

Node* search(Node *p, int key) {
    while(p) {
        if(key == p->data)
            return p;

        p = p->next;
    }

    return NULL;
}

void displayHashTable(Node **HT) {
    for(int i = 0; i<10; ++i) {
        printf("%i: ", i);
        display(HT[i]);
    }
}

int hash(int key) {
    return key % 10;
}

void insert(Node *HT[], int key) {
    int index = hash(key);
    sortedInsert(&HT[index], key);
}

int main(void) {
    Node *HT[10] = {NULL};

    insert(HT, 3);
    insert(HT, 6);
    insert(HT, 22);
    insert(HT, 76);
    insert(HT, 13);
    insert(HT, 33);
    insert(HT, 15);
    insert(HT, 19);
    insert(HT, 20);

    displayHashTable(HT);

    if(search(HT[hash(34)], 34))
        puts("found");
    else
        puts("not found");

    return 0;
}