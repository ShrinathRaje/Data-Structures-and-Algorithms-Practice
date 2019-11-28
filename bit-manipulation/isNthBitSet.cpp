/*
* Check if nth bit is set
* Date: 28th Nov 2019
* Author: Shrinath bhosale
*/

#include<iostream>

using namespace std;

bool isBitSet(int n, int pos) {
	// 1 << i = 2^i
	if(n & (1 << pos))
		return true;
	else
		return false;
}

int main() {
	int n, pos;
	cin >> n >> pos;
	cout << isBitSet(n, pos) << endl;
	return 0;
}
