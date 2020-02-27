//Merge sort

#include<stdio.h>

void merge(int *left, int l_size, int *right, int r_size, int *arr, int size) {
    int i, j, k;
    i = j = k = 0;

    while(i < l_size && j < r_size) {
        if(left[i] <= right[j]) {
            arr[k] = left[i++];
        } else {
            arr[k] = right[j++];
        }

        ++k;
    }

    while(i < l_size) {
        arr[k] = left[i++];
        ++k;
    }

    while(j < r_size) {
        arr[k] = right[j++];
        ++k;
    }
}

/*
Time complexity:-
Worst case: O(n*log(n))

Space complexity: O(n)
*/
void merge_sort(int *arr, int size) {
    if(size < 2)
        return;

    int mid = size / 2;
    int l_size = mid;
    int r_size = size - l_size;

    int left[l_size];
    int right[r_size];

    int k = 0;
    for(int i=0; i<l_size; ++i) {
        left[i] = arr[k++];
    }

    for(int i=0; i<r_size; ++i) {
        right[i] = arr[k++];
    }

    merge_sort(left, l_size);
    merge_sort(right, r_size);
    merge(left, l_size, right, r_size, arr, size);
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

    merge_sort(arr, arr_size);

    print_array(arr, arr_size);

    return 0;
}