//Insertion sort

#include<stdio.h>

/*
Time complexity:-
Best case: O(n), when array is sorted
Worst case: O(n^2)
Average case: O(n^2)
*/
void insertion_sort(int *arr, int size) {
    for(int i=1; i<size; ++i) {
        int val = arr[i];
        int hole = i;

        while(hole > 0 && arr[hole-1] > val) {
            arr[hole] = arr[hole - 1];
            --hole;
        }

        arr[hole] = val;
    }
}

void print_array(int *arr, int size) {
    for(int i=0; i<size; ++i) {
        printf("%i ", arr[i]);
    }

    putchar('\n');
}

int main(void) {
    int arr[] = {5, 3, 8, 2, 1, 6};

    int arr_size = sizeof(arr) / sizeof(int);

    insertion_sort(arr, arr_size);

    print_array(arr, arr_size);

    return 0;
}