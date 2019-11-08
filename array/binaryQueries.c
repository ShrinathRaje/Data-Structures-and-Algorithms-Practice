/*
* Binary Queries
* Date: 8th Nov 2019
* Author: Shrinath Bhosale
* Problem Statement: https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/range-query-2/
*/

#include<stdio.h>

int main(void) {
	int n, q;
	scanf("%i %i", &n, &q);

	int arr[n + 1];
	for(int i=1; i<=n; ++i) {
		scanf("%i", &arr[i]);
	}

	while(q--) {
		int t;
		scanf("%i", &t);

		if(t) {
			int x;
			scanf("%i", &x);
			arr[x] = (arr[x]) ? 0 : 1;
		} else {
			int l, r;
			scanf("%i %i", &l, &r);
			if(arr[r])
				puts("ODD");
			else
				puts("EVEN");
		}
	}
	return 0;
}