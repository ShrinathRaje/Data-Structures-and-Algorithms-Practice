/*
* Fit squares in a triangle
* Date: 7th Dec 2019
* Author: Shrinath Bhosale
* Problem statement: https://www.codechef.com/problems/TRISQ
*/

#include<stdio.h>

int main(void) {
    int t;
    scanf("%i", &t);

    while(t--) {
        int b;
        scanf("%i", &b);

        int n = b/2 - 1;
        printf("%i\n", n * (n + 1) / 2);
    }
    return 0;
}