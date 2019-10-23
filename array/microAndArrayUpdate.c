/*
* Title: Micro and Array Update
* Date: 23rd Oct 2019
* Author: Shrinath Bhosale
* Problem Statement: https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/micro-and-array-update/
*/

#include<stdio.h>
#include<limits.h>

int main(void) {
	int t, n, k;
	
	scanf("%i", &t);
	
	while(t--) {
		scanf("%i %i", &n, &k);
		int arr[n];
		
		int min = INT_MAX;
		for(int i=0; i<n; ++i) {
			scanf("%i", &arr[i]);
			
			if(arr[i] < min)
				min = arr[i];
		}
		
		int ans = k - min;
		printf("%i\n", (ans < 0) ? 0 : ans);
	}
}

