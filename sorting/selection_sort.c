//selection sort

#include<stdio.h>

void swap(int *arr, int i, int min_index) {
    int temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
}

// O(n^2) time complexity
void selection_sort(int *arr, int size) {
    for(int i=0; i<size - 1; ++i)  {
        int min_index = i;

        for(int j=i+1; j<size; ++j) {
            if(arr[j] < arr[min_index])
                min_index = j;
        }

        swap(arr, i, min_index);
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

    selection_sort(arr, arr_size);

    print_array(arr, arr_size);

    return 0;
}