/*
* print all the possible subsets
* Date: 29th Nov 2019
* Author: Shrinath bhosale
*/

#include<iostream>

using namespace std;

void printPossibleSubsets(char arr[], int size) {
	int noOfSubsets = 1 << size;

	for(int i = 0; i < noOfSubsets; ++i) {
		for(int j = 0; j<size; ++j) {
			if(i & (1 << j))
				cout << arr[j] << ' ';
		}

		cout << '\n';
	}
}

int main() {
	char arr[] = {'a', 'b', 'c', 'd'};
	int size = sizeof(arr) / sizeof(char);

	printPossibleSubsets(arr, size);
	return 0;
}
