// Quick sort Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *arr, int index, int pivot_index) {
    int temp = arr[pivot_index];
    arr[pivot_index] = arr[index];
    arr[index] = temp;
}

int partition(int *arr, int start_index, int end_index) {
    int pivot = arr[end_index];
    int pivot_index = start_index;

    for(int i=start_index; i<end_index; ++i) {
        //sort in ascending order
        //for descending order -> arr[i] >= pivot
        if(arr[i] <= pivot) {
            swap(arr, i, pivot_index);
            ++pivot_index;
        }
    }

    swap(arr, end_index, pivot_index);

    return pivot_index;
}

int randomised_partition(int *arr, int start_index, int end_index) {
    //get a random number between start and end index
    int pivot_index = (rand() % (end_index - start_index + 1)) + start_index;
    swap(arr, end_index, pivot_index);
    return partition(arr, start_index, end_index);
}

void quick_sort(int *arr, int start_index, int end_index) {
    if(start_index < end_index) {
        int pivot_index = randomised_partition(arr, start_index, end_index);
        quick_sort(arr, start_index, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, end_index);
    }
}

void print_array(int *arr, int size) {
    for(int i=0; i<size; ++i)
        printf("%i ", arr[i]);

    putchar('\n');
}

int main(void) {
    srand(time(0));
    int arr[] = {5, 10, 3, 7, 2, 9, 1, 4, 8, 6};
    int a[] = {99, 98, 97, 96, 95, 94};

    quick_sort(arr, 0, 9);
    print_array(arr, sizeof(arr) / sizeof(int));

    quick_sort(a, 0, 5);
    print_array(a, sizeof(a) / sizeof(int));
    return 0;
}