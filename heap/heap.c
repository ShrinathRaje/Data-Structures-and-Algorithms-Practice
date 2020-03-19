//creating max heap

#include<stdio.h>

//insertion is O(log n) operation
void insert(int a[], int index) {
    int i = index;

    while(i > 0 && a[i] > a[(i-1) / 2]) {
        int temp = a[i];
        a[i] = a[(i-1) / 2];
        a[(i-1) / 2] = temp;
        i = (i-1) / 2;
    }
}

//creation of heap is O(n * log(n)) operation
void create_heap(int a[], int size) {
    for(int i=1; i<size; ++i) {
        insert(a, i);
    }
}

void print(int a[], int size) {
    for(int i=0; i<size; ++i) {
        printf("%i ", a[i]);
    }

    putchar('\n');
}

int main(void) {
    int a[] = {1,2,3,4,5,6,7};

    create_heap(a, sizeof(a) / sizeof(int));

    print(a, sizeof(a) / sizeof(int));

    return 0;
}