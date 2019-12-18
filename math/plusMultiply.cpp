/*
* Plus multiply
* Date: 18th dec 2019
* Author: Shrinath Bhosale
* Problem statement: https://www.codechef.com/problems/PLMU
*/

#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		/*
		int arr[n];
		for(int i=0; i<n; ++i)
			cin >> arr[i];

		//brute force
		long count = 0;
		for(int i=0; i<n; ++i) {
			for(int j=i+1; j<n; ++j) {
				if(arr[i] + arr[j] == arr[i]*arr[j])
					++count;
			}
		}
		*/

		int count_2 = 0, count_0 = 0;
		for(int i=0; i<n; ++i) {
			int a;
			cin >> a;
			if(a == 2)
				++count_2;
			else if(a == 0)
				++count_0;
		}

		cout << count_2 * (count_2 - 1) / 2 + count_0 * (count_0 - 1) / 2 << endl;
	}
	return 0;
}