/*
* Title: check if a string is palindrome or not
* Date: 7th Oct 2019
* Author: Shrinath Bhosale
* Problem Statement: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/palindrome-check-2/
*/

#include<stdio.h>
#include<string.h>

int main(void) {
    char str[101];
    
    scanf("%s", str);
    int l = strlen(str);
    int j = l - 1;
    for(int i=0; i <= j; ++i, --j) {
        if(str[i] != str[j]) {
            puts("NO");
            return 0;
        }
    }
    
    puts("YES");
    return 0;
}
