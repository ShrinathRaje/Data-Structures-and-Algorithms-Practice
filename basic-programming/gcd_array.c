#include<stdio.h>

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main(void) {
	int t;
	scanf("%i", &t);
	
	while(t--) {
		int n;
		scanf("%i", &n);
		
		int result;
		scanf("%i", &result);
		
		for(int i=0; i<n-1; ++i) {
			int el;
			scanf("%i", &el);
			result = gcd(el,result);
		}
		
		printf("%i\n", result);
	}
	
	return 0;
}
