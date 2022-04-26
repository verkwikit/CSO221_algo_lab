#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cout << "\nEnter the number of vertices: ";
	cin >> n;
	
	cout << "\nEnter the number of edges: ";
	cin >> m;

	vector<vector<int>> adj(n);
	// adjacency list of the graph
	cout << "\nEnter the vertices which are connected using the edges.\n";
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	vector<bool> vis(n);
	// visited array, to check if the node has been traversed yet or not
	vector<int> bfs;
	// to maintain the order of nodes in which they are traversed

	queue<int> queue1;
	for (int i = 0; i < n; i++) {
		if (vis[i])	continue;

		queue1.push(i);
		while (!queue1.empty()) {
			int x = queue1.front();
			queue1.pop();

			if (vis[x])	continue;

			vis[x] = 1;
			bfs.push_back(x);
			for (int y : adj[x]) {
				if (vis[y])	continue;
				queue1.push(y);
			}
		}
	}
	
	cout << "\nThe BFS traversal order is : \n";
	for (int i = 0; i < n; i++) {
		cout << bfs[i] << ' ';
	}
	cout << "\n\n";

	return 0;
}