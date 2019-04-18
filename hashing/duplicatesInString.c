/* Duplicates in String */
/* Date: 18th Apr 2019 */
/* Author: Shrinath Bhosale */

#include<stdio.h>

int main(void) {
    char str[100];
    char hash[26] = {0};

    puts("Enter a string");
    scanf("%[a-z]s", str);

    for(int i=0; str[i] != '\0'; ++i) {
        ++hash[str[i] - 'a'];
    }

    for(int i=0; i<26; ++i) {
        if(hash[i] > 1) {
            printf("character '%c' is repeating %i times\n", i+'a', hash[i]);
        }
    }
    
    return 0;
}