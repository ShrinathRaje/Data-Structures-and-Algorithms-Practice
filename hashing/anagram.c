/* Anagram */
/* Date: 18th Apr 2019 */
/* Author: Shrinath Bhosale */

#include<stdio.h>
#include<stdbool.h>

bool isAnagram(const char *str1, const char *str2) {
    int hash[26] = {0};

    for(int i=0; str1[i] != '\0'; ++i) {
        ++hash[str1[i] - 'a'];
    }

    for(int j=0; str2[j] != '\0'; ++j) {
        int d = str2[j] - 'a';
        --hash[d];
        if(hash[d] < 0) {
            return false;
        }
    }

    return true;
    
}

int main(void) {
    printf("%i\n", isAnagram("listen", "silent"));
    printf("%i\n", isAnagram("shri", "shre"));
    printf("%i\n", isAnagram("fried", "fired"));

    return 0;
}