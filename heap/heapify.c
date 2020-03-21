//heapify method
//time complexity: O(n)
#include<stdio.h>

void heapify(int a[], int size, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < size && a[l] > a[largest])
        largest = l;

    if(r < size && a[r] > a[largest])
        largest = r;

    if(largest != i) {
        int t = a[i];
        a[i] = a[largest];
        a[largest] = t;

        heapify(a, size, largest);
    }
}

void create_heap(int a[], int size) {
    //last non leaft node
    int n = size/2 - 1;

    for(int i=n; i>=0; --i) {
        heapify(a, size, i); 
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
    int size = sizeof(a) / sizeof(int);

    create_heap(a, size);

    print(a, size);

    return 0;
}