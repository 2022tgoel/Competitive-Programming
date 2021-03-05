/*
Given two rooted trees, your task is to find out if they are isomorphic, i.e., it is possible to draw them so that they look the same.

Input

The first input line has an integer t: the number of tests. Then, there are t tests described as follows:

The first line has an integer n: the number of nodes in both trees. The nodes are numbered 1,2,…,n, and node 1 is the root.

Then, there are n−1 lines describing the edges of the first tree, and finally n−1 lines describing the edges of the second tree.

Output

For each test, print "YES", if the trees are isomorphic, and "NO" otherwise.

Constraints
1≤t≤1000
2≤n≤105
the sum of all values of n is at most 105
Example

Input:
2
3
1 2
2 3
1 2
1 3
3
1 2
2 3
1 3
3 2

Output:
NO
YES
*/

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
bool ans;

int DFS1(vector<vector<int>>& tree, int cur, int depth, vector<bool>& visit, multiset<pii>& nodes){
	visit[cur] = true;
	int sz = 1;
	for (int child : tree[cur]){
		if (visit[child] == false) sz+=DFS1(tree, child, depth+1, visit, nodes);
	}
	nodes.insert(make_pair(depth, sz));
	return sz;
}

int DFS2(vector<vector<int>>& tree, int cur, int depth, vector<bool>& visit, multiset<pii>& nodes){
	visit[cur] = true;
	int sz = 1;
	for (int child : tree[cur]){
		if (visit[child] == false) sz+=(DFS2(tree, child, depth+1, visit, nodes));
	}
	pii x = make_pair(depth, sz);
	if (nodes.count(x) == 0) ans= false;
	else nodes.erase(nodes.lower_bound(x));
	return sz;
}

int main(){
	int t;
	cin >> t;
	for (int j = 0; j < t; j++){
		int n;
		cin >> n;
		vector<vector<int>> tree1(n+1);
		vector<vector<int>> tree2(n+1);
		multiset<pii> nodes; //(depth, # of children) = # of nodes with key
		for (int i = 0; i < n-1; i++){
			int a, b;
			cin >> a >> b;
			tree1[a].push_back(b);
			tree1[b].push_back(a);
		}
		for (int i = 0; i < n-1; i++){
			int a, b;
			cin >> a >> b;
			tree2[a].push_back(b);
			tree2[b].push_back(a);
		}
		vector<bool> visit(n+1, 0);
		DFS1(tree1, 1, 0, visit, nodes);
		fill(visit.begin(), visit.end(), 0);
		ans = true;
		DFS2(tree2, 1, 0, visit, nodes);
		cout << ((!ans) ? "NO" : "YES") << endl;
	}
}