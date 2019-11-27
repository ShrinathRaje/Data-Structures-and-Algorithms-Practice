/*
* Digit problem
* Date: 27th Nov 2019
* Author: Shrinath bhosale
* Problem statement: https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/digit-problem/
*/

#include<iostream>

using namespace std;

int main() {
	string s;
	int k;
	cin >> s >> k;
	int l = s.size();

	for(int i=0, c = 0; i<l && c != k; ++i) {
		if(s[i] != '9') {
			s[i] = '9';
			++c;
		}
	}

	cout << s;
	return 0;
}
