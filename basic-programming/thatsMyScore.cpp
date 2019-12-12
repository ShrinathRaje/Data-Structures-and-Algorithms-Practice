/*
* That is my score
* Date: 7th dec 2019
* Author: Shrinath Bhosale
* Problem statement: https://www.codechef.com/DEC19B/problems/WATSCORE
*/

#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		int a[9] = {0};
		cin >> n;

		while(n--) {
			int p, s;
			cin >> p >> s;
			if(p < 9 && s > a[p])
				a[p] = s;
		}

		int sum = 0;
		for(int i=1; i<9; ++i) {
			sum += a[i];
		}

		cout << sum << "\n";
	}
	return 0;
}