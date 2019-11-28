/*
* Count set bits
* Date: 28th Nov 2019
* Author: Shrinath bhosale
*/

#include<iostream>

using namespace std;

int countSetBits(int n) {
	// n & (n - 1) flips the rightmost set bit. Ohter bits remains unchanged.
	// all the set bits will be flipped one by one from right to left until we get the zero
	int count = 0;
	while(n) {
		n = n & (n - 1);
		++count;
	}

	return count;
}

int main() {
	int n;
	cin >> n;
	cout << countSetBits(n) << endl;
	return 0;
}
