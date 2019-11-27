/*
* Vowel recognition
* Date: 27th Nov 2019
* Author: Shrinath bhosale
* Problem statement: https://www.hackerearth.com/practice/basic-programming/complexity-analysis/time-and-space-complexity/practice-problems/algorithm/vowel-game-f1a1047c/
*/

#include<iostream>
#include<cstring>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		char str[100001];
		cin >> str;
		
		long l = strlen(str);
		long total = 0;
		for(long i=0; i<l; ++i) {
			char c = str[i];
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
				total += (l - i)*(i+1);
			}
		}
		
		cout << total << endl;
	}

	return 0;
}
