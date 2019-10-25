/*
* Title: Balanced Brackets
* Date: 25th Oct 2019
* Author: Shrinath Bhosale
* Problem Statement: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/balanced-brackets-3-4fc590c6/
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node {
	char c;
	Node *next;
};

void push(Node **top, char c) {
	Node *n = malloc(sizeof(Node));
	n->c = c;
	n->next = NULL;
	
	if(*top != NULL) {
		n->next = *top;
	}
	
	*top = n;
	//printf("push %c ", n->c);
}

char pop(Node **top) {
	if(*top == NULL)
		return '\0';
		
	Node *temp = *top;
	*top = (*top)->next;
	char c = temp->c;
	free(temp);
	
	//printf("pop %c ", c);
	return c;
}

int isSameType(char c1, char c2) {
	if(c1 == ')' && c2 == '(' || c1 == ']' && c2 == '[' || c1 == '}' && c2 == '{')
		return 1;
	else
		return 0;
}

int main(void) {
	int n;
	scanf("%i", &n);
	
	while(n--) {
		Node *top = NULL;
		char str[1001];
		char *ans;
		int f = 0;
		scanf("%s", str);
		
		for(int i=0; str[i] != '\0'; ++i) {
			char c1 = str[i];
			if(c1 == '{' || c1 == '(' || c1 == '[')
				push(&top, c1);
			else {
				char c2 = pop(&top);
				if(c2 == '\0') {
					printf("%s\n", "NO");
					f = 1;
					break;
				}
				if(isSameType(c1, c2))
					continue;
				else {
					f = 1;
					printf("%s\n", "NO");
					break;
				}
			}
		}
		
		if(!f)
			printf("%s\n", (top == NULL) ? "YES" : "NO");
	}
	
	return 0;
}

