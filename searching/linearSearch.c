/* Improved Linear Search */
/* Date: 17th Apr 2019 */
/* Author: Shrinath Bhosale */

#include<stdio.h>

typedef struct Array Array;

struct Array {
    int a[20];
    int size;
    int length;
};

void display(Array arr) {
    for(int i=0; i<arr.length; ++i) {
        printf("%i ", arr.a[i]);
    }

    putchar('\n');
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(Array *arr, int key) {
    for(int i=0; i<arr->length; ++i) {
        if(key == arr->a[i]) {
            // improving the linear search by moving the found element to the front
            swap(&arr->a[i], &arr->a[0]);
            return i;
        }
    }

    fprintf(stderr, "err: element not found!\n");
    return -1;
}

int main(void) {
    Array arr = {{1, 2, 3, 4, 5}, 20, 5};

    printf("%i\n", linearSearch(&arr, 3));

    display(arr);

    return 0;
}