/*
* Title: Reversed Linked List
* Date: 24th Oct 2019
* Author: Shrinath Bhosale
* Problem Statement: https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/practice-problems/algorithm/reversed-linked-list-01b722df/description/
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} node;

node *head, *tail, *top;

node* getNode(int num) {
	node *n = malloc(sizeof(node));
	n->data = num;
	n->next = NULL;
	
	return n;
}

void insertInLL(int num) {
	node *n = getNode(num);
	
	if(tail == NULL) {
		head = tail = n;
	} else {
		tail->next = n;
		tail = n;
	}
}

void pushInStack(int num) {
	node *n = getNode(num);
	
	if(top != NULL)
		n->next = top;
		
	top = n;
}

void popFromStack() {
	while(top != NULL) {
		printf("%i ", top->data);
		node *temp = top;
		top = top->next;
		free(temp);
	}
}

int main(void) {
	head = tail = top = NULL;
	int n;
	
	scanf("%i", &n);
	while(n--) {
		int num;
		scanf("%i", &num);
		insertInLL(num);
	}
	
	node *t = head;
	while(t != NULL) {
		if(t->data % 2 == 0) {
			pushInStack(t->data);
		} else {
			popFromStack();
			printf("%i ", t->data);
		}
		
		t = t->next;
	}
	
	popFromStack();
}

