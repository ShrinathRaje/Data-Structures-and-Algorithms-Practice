#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void dfs(int n, vector <int> al[]) {
	stack <int> s;
	bool visited[1001] = {false};

	s.push(n);
	visited[n] = true;

	while(!s.empty()) {
		int p = s.top();
		s.pop();
		cout << p << " ";

		for(int i=0; i<al[p].size(); ++i) {
			if(!visited[al[p][i]]) {
				s.push(al[p][i]);
				visited[al[p][i]] = true;
			}
		}
	}

	cout << "\n";
}

void dfs_recursive(int n, vector<int> al[]) {
	static bool visited[1001] = {false};
	visited[n] = true;
	cout << n << " ";

	for(int i=0; i<al[n].size(); ++i) {
		if(!visited[al[n][i]]) {
			dfs_recursive(al[n][i], al);
		}
	}
}

int main() {
	int vertices, edges;
	cin >> vertices >> edges;

	// 1 <= n <= 1000
	vector <int> al[1001];
	
	for(int i=0; i<edges; ++i) {
		int a, b;
		cin >> a >> b;
		
		//graph is undirected
		al[a].push_back(b);
		al[b].push_back(a);
	}

	dfs(1, al);
	dfs(5, al);

	// dfs_recursive(1, al);
	// cout << endl;
	dfs_recursive(5, al);
	cout << endl;

	return 0;
}