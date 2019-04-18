/* Duplicates in String */
/* Date: 18th Apr 2019 */
/* Author: Shrinath Bhosale */

#include<stdio.h>

/* find duplicates in string using bitwise operations 

void findDuplicates(const char *str) {
    int h = 0;
    for(int i = 0; str[i] != '\0'; ++i) {
        int x = 1;
        x = x << (str[i] - 'a');
        
        if((x & h) > 0) {
            printf("character '%c' is duplicate\n", str[i]);
        } else {
            h = h | x;
        }
    }
}

*/

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
