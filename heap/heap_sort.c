//heap sort technique

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

//O(log(n))
int delete(int a[], int last_index) {
    int temp = a[0];
    a[0] = a[last_index];
    a[last_index] = temp;

    int i = 0;
    int j = 2*i + 1;
    while(j < last_index - 1) {
        if(j < last_index-1 && a[j+1] > a[j])
            ++j;

        if(a[i] < a[j]) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i = j;
            j = 2*j + 1;
        } else {
            break;
        }
    }

    return temp;
}

//O(n log(n))
void heap_sort(int a[], int size) {
    for(int i=size-1; i>0; --i) {
        delete(a, i);
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

    heap_sort(a, size);

    print(a, size);

    return 0;
}