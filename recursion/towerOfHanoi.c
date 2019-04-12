/* Tower of Hanoi */
/* Date: 12th Apr 2019 */
/* Author: Shrinath Bhosale */

#include<stdio.h>

#define NO_OF_DISKS 5

void TOH(int n, char src, char aux, char dest) {
    if(n > 0) {
        TOH(n-1, src, dest, aux);
        printf("%c to %c\n", src, dest);
        TOH(n-1, aux, src, dest);
    }
}

int main(void) {
    TOH(NO_OF_DISKS, 'A', 'B', 'C');
    return 0;
}