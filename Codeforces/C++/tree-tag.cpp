/*
B. Tree Tag
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alice and Bob are playing a fun game of tree tag.

The game is played on a tree of n vertices numbered from 1 to n. Recall that a tree on n vertices is an undirected, connected graph with n−1 edges.

Initially, Alice is located at vertex a, and Bob at vertex b. They take turns alternately, and Alice makes the first move. In a move, Alice can jump to a vertex with distance at most da from the current vertex. And in a move, Bob can jump to a vertex with distance at most db from the current vertex. The distance between two vertices is defined as the number of edges on the unique simple path between them. In particular, either player is allowed to stay at the same vertex in a move. Note that when performing a move, a player only occupies the starting and ending vertices of their move, not the vertices between them.

If after at most 10100 moves, Alice and Bob occupy the same vertex, then Alice is declared the winner. Otherwise, Bob wins.

Determine the winner if both players play optimally.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). Description of the test cases follows.

The first line of each test case contains five integers n,a,b,da,db (2≤n≤105, 1≤a,b≤n, a≠b, 1≤da,db≤n−1)  — the number of vertices, Alice's vertex, Bob's vertex, Alice's maximum jumping distance, and Bob's maximum jumping distance, respectively.

The following n−1 lines describe the edges of the tree. The i-th of these lines contains two integers u, v (1≤u,v≤n,u≠v), denoting an edge between vertices u and v. It is guaranteed that these edges form a tree structure.

It is guaranteed that the sum of n across all test cases does not exceed 105.

Output
For each test case, output a single line containing the winner of the game: "Alice" or "Bob".
*/

#include <bits/stdc++.h>
using namespace std;

void DFS(int cur, vector<vector<int>>& graph, vector<int>& depth, vector<bool>& v){
	v[cur] = true;
	for (int child : graph[cur]){
		if (!v[child]){
			depth[child] = depth[cur]+1;
			DFS(child, graph, depth, v);
		}
	}
}

int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int n, a, b, da, db;
		cin >> n >> a >> b >> da >> db;
		a--; b--;
		vector<vector<int>> graph(n);
		vector<int> depth(n);
		vector<bool> v(n);
		for (int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			x--; y--;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		if (db<=2*da){
			cout << "Alice" << endl;
			continue;
		}
		DFS(a, graph, depth, v);
		if (depth[b] <=da) {
			cout << "Alice" << endl;
			continue;
		}
		int md = 0;
		for (int i = 0; i < n;i++) 
			if (depth[i] > depth[md]) md = i;
		for (int i = 0; i < n; i++) v[i]= false;
		depth[md] = 0;
		DFS(md, graph, depth, v);
		int diam = 0;
		for (int i = 0; i < n; i++)
			if (depth[i]+1 > diam) diam = depth[i];
		if (diam <= 2*da){
			cout << "Alice" << endl;
			continue;
		}
		cout << "Bob" << endl;
	}
}