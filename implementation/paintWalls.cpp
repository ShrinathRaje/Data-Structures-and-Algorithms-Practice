/*
* Paint Walls
* Date: 7th dec 2019
* Author: Shrinath Bhosale
* Problem statement: https://www.hackerearth.com/problem/algorithm/paint-the-wall-1-c312265d/
*/

#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;

		int a[n][m];
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				cin >> a[i][j];

		
		long min_cost = -1;

		//for (2, k)
		if(k <= m && n >= 2) {
			for(int i=0; i+2 <= n; ++i) {
				for(int j=0; j + k <= m; ++j) {
					long cost = 0;
					for(int x=i; x<i+2; ++x) {
						for(int y=j; y<j+k; ++y) {
							cost += a[x][y];
						}
					}

					if(cost < min_cost || min_cost == -1)
						min_cost = cost;
				}
			}
		}
		

		//for (k, 2)
		if(k <= n && m >= 2) {
			for(int i=0; i+k <= n; ++i) {
				for(int j=0; j+2 <= m; ++j) {
					long cost = 0;
					for(int x=i; x<i+k; ++x) {
						for(int y=j; y<j+2; ++y) {
							cost += a[x][y];
						}
					}

					if(cost < min_cost || min_cost == -1)
						min_cost = cost;
				}
			}
		}
		

		cout << min_cost << "\n";

	}
	
	return 0;
}