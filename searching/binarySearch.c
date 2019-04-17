/* Binary Search Implementation */
/* Date: 17th Apr 2019 */
/* Author: Shrinath Bhosale */


#include<stdio.h>

/* Iterative method */
int binarySearch(int *arr, int l, int r, int key) {
    while(l <= r) {
        int m = l + (r-l)/2;

        if(key == arr[m])
            return m;
        else if(key < arr[m])
            r = m - 1;
        else
            l = m + 1;

    }

    return -1;
}

/* recursive method */
int binarySearchRecursive(int *arr, int l, int r, int key) {
    if(l <= r) {
        int m = l + (r-l)/2;

        if(key == arr[m])
            return m;
        else if(key < arr[m])
            return binarySearchRecursive(arr, l, m-1, key);
        else
            return binarySearchRecursive(arr, m+1, r, key);
    }

    return -1;
}

int main(void) {
    int arr[] = {2, 4, 5, 8, 12, 15};
    int length = sizeof(arr) / sizeof(int);

    printf("%i\n", binarySearch(arr, 0, length - 1, 99));
    printf("%i\n", binarySearch(arr, 0, length - 1, 4));
    printf("%i\n", binarySearch(arr, 0, length - 1, 15));

    printf("%i\n", binarySearchRecursive(arr, 0, length - 1, 99));
    printf("%i\n", binarySearchRecursive(arr, 0, length - 1, 4));
    printf("%i\n", binarySearchRecursive(arr, 0, length - 1, 15));

    return 0;
}