#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(int n, vector <int> al[]) {
	queue <int> q;
	bool visited[1001] = {false};

	cout << n << " ";
	q.push(n);
	visited[n] = true;

	while(!q.empty()) {
		int p = q.front();
		q.pop();

		for(int i=0; i<al[p].size(); ++i) {
			if(!visited[al[p][i]]) {
				cout << al[p][i] << " ";
				q.push(al[p][i]);
				visited[al[p][i]] = true;
			}
		}
	}

	cout << "\n";

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

	bfs(1, al);
	bfs(5, al);

	return 0;
}