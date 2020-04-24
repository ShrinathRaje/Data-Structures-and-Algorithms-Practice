/*
* knapsack problem naive approach
* Date: 24th April
* Author: Shrinath Bhosale
* Problem: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0/
*/

#include<iostream>

using namespace std;

int knapsack(int w[], int v[], int W, int n) {
	if(W == 0 || n == 0)
		return 0;

	if(w[n-1] > W)
		return knapsack(w, v, W, n-1);

	else return max(v[n-1] + knapsack(w, v, W - w[n-1], n-1), knapsack(w, v, W, n-1));
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, W;
		cin >> n >> W;

		int v[n], w[n];

		for(int i=0; i<n; ++i)
			cin >> v[i];

		for(int i=0; i<n; ++i)
			cin >> w[i];

		cout << knapsack(w, v, W, n) << "\n";
	}

	return 0;
}