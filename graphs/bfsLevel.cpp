#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void level(int n, int v, vector <int> al[]) {
	queue <int> q;
	bool visited[1001] = {false};
	int level[1001] = {0};

	q.push(n);
	visited[n] = true;

	while(!q.empty()) {
		int p = q.front();
		q.pop();

		for(int i=0; i<al[p].size(); ++i) {
			int vertex = al[p][i];

			if(!visited[vertex]) {
				q.push(vertex);
				visited[vertex] = true;
				level[vertex] = level[p] + 1;
			}
		}
	}

	for(int i=1; i<=v; ++i) {
		cout << i << " " << level[i] << "\n";
	}

	putchar('\n');

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

	level(1, vertices, al);
	level(5, vertices, al);

	return 0;
}