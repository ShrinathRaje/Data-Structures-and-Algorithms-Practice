/*
* count set bits, use fast IO
* Date: 29th Nov 2019
* Author: Shrinath bhosale
*/

#include<iostream>

using namespace std;

int countSetBits(long n) {
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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long n;
	while(cin >> n) {
		cout << countSetBits(n) << "\n";
	}
	return 0;
}
