/*
* Prime Numbers - Sieve Of Eratosthenes
* Date: 1st Nov 2019
* Author: Shrinath Bhosale
* Problem Statement: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/prime-number-8/
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

int main(void) {
	int n;
	scanf("%i", &n);

	bool primes[n+1];
	memset(primes, true, sizeof(primes));

	long s = (long) ceil(sqrt(n));
	for(int i=2; i<=s; ++i) {
		if(primes[i]) {
			for(int j=i; i*j <= n; ++j) {
				primes[i*j] = false;
			}
		}
	}

	for(int i=2; i<=n; ++i) {
		if(primes[i])
			printf("%i ", i);
	}

	putchar('\n');
	return 0;
}