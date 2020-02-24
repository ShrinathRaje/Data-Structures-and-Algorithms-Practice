//Bubble sort

#include<stdio.h>

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/*
Time complexity:-
Best case: O(n), when array is already sorted
Worst case: O(n^2)
Average case: O(n^2)
*/
void bubble_sort(int *arr, int size) {
    for(int i=1; i<size; ++i) {
        int is_sorted = 1;

        /*
        Highest number gets bubbled up on each iteration, thus array gets divided into sorted and unsorted part. Thus, there's no need to run the below loop till (size - 1) everytime. 
        */
        for(int j=0; j<size-i; ++j) {
            if(arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
                is_sorted = 0;
            }
        }

        //if array is already sorted, no need to perform redundant swaps
        if(is_sorted)
            break;
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

    bubble_sort(arr, arr_size);

    print_array(arr, arr_size);

    return 0;
}