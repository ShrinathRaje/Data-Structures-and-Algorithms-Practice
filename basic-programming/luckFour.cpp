/*
* Lucky Four
* Date: 5th Dec 2019
* Author: Shrinath Bhosale
* Problem statement: https://www.codechef.com/problems/LUCKFOUR
*/

#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		string s;
		cin >> s;

		int l = s.length();
		int count = 0;
		for(int i=0; i<l; ++i) {
			if(s[i] == '4')
				++count;
		}

		cout << count << "\n";
	}
	return 0;
}
