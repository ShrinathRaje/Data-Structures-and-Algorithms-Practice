/*
* Undirected Graph
* Date: 20th dec 2019
* Author: Shrinath Bhosale
* Problem statement: https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/tutorial/
*/

#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, e, q;
	cin >> n >> e;

	vector <int> al[1001];
	
	for(int i=0; i<e; ++i) {
		int a, b;
		cin >> a >> b;
		
		//graph is undirected
		al[a].push_back(b);
		al[b].push_back(a);
	}

	cin >> q;
	for(int i=0; i<q; ++i) {
		int a, b;
		cin >> a >> b;

		bool c = false;
		for(int j=0; j<al[a].size(); ++j) {
			if(al[a][j] == b) {
				cout << "YES" << "\n";
				c = true;
				break;
			}	
		}

		if(!c)
			cout << "NO" << "\n";
	}
	return 0;
}