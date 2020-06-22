//N Queens

#include<bits/stdc++.h>

using namespace std;

bool isSafe(int b[][11], int r, int c, int n) {
	//check the same column
	for(int i=0; i<r; ++i)
		if(b[i][c])
			return false;

	//check the left diagonal
	int x = r, y = c;
	while(x>=0 && y>=0) {
		if(b[x--][y--])
			return false;
	}


	//check the right diagonal
	x = r, y = c;
	while(x>=0 && y<n) {
		if(b[x--][y++])
			return false;
	}

	return true;
}

bool solveNQueen(int b[][11], int r, int n) {
	if(r == n) {
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				cout << b[i][j] << " ";
			}

			cout << "\n";
		}

		cout << "\n";

		//to print one solution
		//return true;

		//to print all solutions
		return false;
	}

	for(int c=0; c<n; ++c) {
		if(isSafe(b, r, c, n)) {
			b[r][c] = 1;

			if(solveNQueen(b, r+1, n))
				return true;

			b[r][c] = 0;
		}
	}

	return false;
} 

int main() {
	int n;
	cin >> n;

	if(n > 10)
		return 0;

	// 1 <= n <= 10
	int b[11][11] = {0};

	solveNQueen(b, 0, n);

	return 0;
}