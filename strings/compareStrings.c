#include<stdio.h>
#include<string.h>

/*
* returns
* 1, if s1 > s2
* -1, if s1 < s2
* 0, if s1 = s2
*/
int compare_string(const char *s1, int l1, const char *s2, int l2) {
    int max_length = (l1 >= l2) ? l1 : l2;
    int max_length_str = (l1 >= l2) ? 1 : 2;

    int min_length = (l1 <= l2) ? l1 : l2;

    for(int i=0; i<max_length; ++i) {

        if(i == min_length) {
            switch (max_length_str) {
                case 1:
                    return 1;
                case 2:
                    return -1;
            }
        }

        if(s1[i] < s2[i])
            return -1;
        
        if(s1[i] > s2[i])
            return 1;
    }

    return 0;
}

int main(void) {
    char str1[100], str2[100];
    scanf("%99s %99s", str1, str2);

    int result = compare_string(str1, strlen(str1), str2, strlen(str2));

    switch (result) {
        case 1:
            printf("%s is greater than %s\n", str1, str2);
            break;
        case 0:
            printf("%s is equal to %s\n", str1, str2);
            break;
        case -1:
            printf("%s is greater than %s\n", str2, str1);
            break;
    }

    return 0;
}