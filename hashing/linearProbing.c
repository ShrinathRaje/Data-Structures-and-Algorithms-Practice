/* Hashing | linear probing */
/* Date: 1st May 2019 */
/* Author: Shrinath Bhosale */

#include<stdio.h>

#define SIZE 10

int hash(int key) {
    return key % 10;
}

int probe(int HT[], int key) {
    int index = hash(key);

    int i = 0;

    while(HT[(index + i) % SIZE] != 0)
        ++i;

    return (index + i) % SIZE;
}

void display(int HT[]) {
    for(int i=0; i<SIZE; ++i) {
        printf("%i: %i\n", i, HT[i]);
    }
}

void insert(int HT[], int key) {
    int index = hash(key);

    if(HT[index] != 0)
        index = probe(HT, key);

    HT[index] = key;
}

int search(int HT[], int key) {
    int index = hash(key);

    int i = 0;
    while(1){
        int j = (index + i) % SIZE;

        if(HT[j] == 0)
            return -1;

        if(HT[j] == key)
            return j;

        ++i;
    }

    return -1;
    
}

int main(void) {
    int HT[SIZE] = {0};

    insert(HT, 10);
    insert(HT, 17);
    insert(HT, 23);
    insert(HT, 13);
    insert(HT, 36);
    insert(HT, 54);

    display(HT);

    printf("%i\n", search(HT, 11));
    printf("%i\n", search(HT,13));
    printf("%i\n", search(HT,33));
    printf("%i\n", search(HT,36));
    
    return 0;
}