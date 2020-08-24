//KMP(Knuth-Morris-Pratt) pattern matching algorithm

#include<iostream>

using namespace std;

void computeLPS(int *lps, const string &p) {
	int m = p.length();

	lps[0] = 0;
	int i = 0, j = 1;

	while(j < m) {
		if(p[i] == p[j]) {
			++i;
			lps[j++] = i;
		} else {
			if(i)
				i = lps[i-1];
			else
				lps[j++] = 0;
		}
	}
}


//time: O(n + m)
int searchPattern(const string &s, const string &p) {
	int n = s.length();
	int m = p.length();

	//longest prefix suffix array
	int lps[m];

	computeLPS(lps, p);

	int i = 0, j = 0;

	while(i < n) {
		if(s[i] == p[j]) {
			++i;
			++j;
		} else {
			if(j)
				j = lps[j-1];
			else
				++i;
		}

		if(j == m)
			return i - j;
	}

	return -1;
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		string s, p;
		cin >> s >> p;

		cout << searchPattern(s, p) << "\n";
	}

	return 0;
}
