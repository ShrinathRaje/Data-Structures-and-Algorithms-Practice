/*
* Power of two
* Date: 28th Nov 2019
* Author: Shrinath bhosale
*/

#include<iostream>

using namespace std;

int isPowOfTwo(int n) {
	// n & (n - 1) flips the rightmost set bit. Ohter bits remains unchanged.
	// power of 2 has only one set bit  
	return (n && !(n & (n - 1)));
}

int main() {
	int n;
	cin >> n;
	cout << isPowOfTwo(n) << endl;
	return 0;
}
