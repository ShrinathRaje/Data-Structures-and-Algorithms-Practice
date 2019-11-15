/*
* Remove Friends
* Date: 15th Nov 2019
* Author: Shrinath Bhosale
* Problem Statement: https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/practice-problems/algorithm/remove-friends-5/
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node {
	int p;
	Node *prev;
	Node *next;
} *head = NULL, *tail = NULL;

void add(int p) {
	Node *n = malloc(sizeof(Node));
	n->p = p;
	n->next = NULL;

	if(head == NULL) {
		n->prev = NULL;
		head = tail = n;
	} else {
		n->prev = tail;
		tail->next = n;
		tail = n;
	}
}

int delete(Node *n) {
	if(n == head) {
		head = n->next;
		head->prev = NULL;
	} else if (n == tail){
		(n->prev)->next = NULL;
		tail = n->prev;
	} else {
		(n->prev)->next = n->next;
		(n->next)->prev = n->prev;
	}

	free(n);
}

void freeAll() {
	Node *n = head;
	while(n) {
		Node *t = n;
		n = n->next;
		free(t);
	}

	head = tail = NULL;
}

void display() {
	Node *n = head;
	while(n) {
		printf("%i ", n->p);
		n = n->next;
	}

	putchar('\n');
}

int main(void) {
	int t;
	scanf("%i", &t);

	while(t--) {
		int n, d;
		scanf("%i %i", &n, &d);

		for(int i=0; i<n; ++i) {
			int p;
			scanf("%i", &p);
			add(p);
		}

		Node *node = head;
		for(int i=0; i<d; ++i) {
			int r = 0;
			while(node->next) {
				if(node->p < (node->next)->p) {
					Node *temp = node;
					if(node == head)
						node = node->next;
					else
						node = node->prev;

					delete(temp);
					r = 1;
					break;
				}

				node = node->next;
			}

			if(!r) {
				delete(tail);
			}

		}

		display();

		//prevent memory leaks
		freeAll();
	}

	return 0;
}