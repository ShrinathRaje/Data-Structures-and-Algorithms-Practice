/*
* Toggle String
* Date: 6th Nov 2019
* Author: Shrinath Bhosale
* Problem Statement: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/modify-the-string/
*/

#include<stdio.h>

int main(void) {
	char str[101];
	scanf("%s", str);

	for(int i=0; str[i] != '\0'; ++i) {
		(str[i] <= 90 && str[i] >= 65) ? putchar(97 + str[i] - 65) : putchar(65 + str[i] - 97);
	}

	putchar('\n');
	return 0;
}