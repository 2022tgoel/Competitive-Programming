/*
D. Segment Tree
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
As the name of the task implies, you are asked to do some work with segments and trees.

Recall that a tree is a connected undirected graph such that there is exactly one simple path between every pair of its vertices.

You are given n segments [l1,r1],[l2,r2],…,[ln,rn], li<ri for every i. It is guaranteed that all segments' endpoints are integers, and all endpoints are unique — there is no pair of segments such that they start in the same point, end in the same point or one starts in the same point the other one ends.

Let's generate a graph with n vertices from these segments. Vertices v and u are connected by an edge if and only if segments [lv,rv] and [lu,ru] intersect and neither of it lies fully inside the other one.

For example, pairs ([1,3],[2,4]) and ([5,10],[3,7]) will induce the edges but pairs ([1,2],[3,4]) and ([5,7],[3,10]) will not.

Determine if the resulting graph is a tree or not.

Input
The first line contains a single integer n (1≤n≤5⋅105) — the number of segments.

The i-th of the next n lines contain the description of the i-th segment — two integers li and ri (1≤li<ri≤2n).

It is guaranteed that all segments borders are pairwise distinct.

Output
Print "YES" if the resulting graph is a tree and "NO" otherwise
*/

#include <iostream>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;
int N;
int starts[500000], opp[1000010], par[1000010], sz[1000010];
set<int> endps;
int find(int ind){
	if(par[ind] == ind) return ind;
	else {
		ind = find(par[ind]);
		return ind;
	}
}
int unite(int a, int b){
	a = find(a);
	b = find(b);
	if (sz[b] > sz[a]){
		int temp = a;
		a = b;
		b = temp;
	}
	par[b] = a;
	sz[a]+=sz[b];
}
int main(){
	cin >> N;
	for (int i = 0 ;i < N; i++){
		int a, b;
		cin >> a >> b;
		starts[i] = a;
		opp[a] = b;
		opp[b] = a;  
		//union-find
		par[a] = a;
		sz[a] = 1;
	} //O(N)
	sort(starts, starts+N);
	int edges = 0;
	for (int i = 0; i < N; i++){
		int cur = starts[i];
		while (endps.size() > 0 && *endps.begin() < cur) endps.erase(*endps.begin());
		for (int end : endps){
			if (end > opp[cur]) break;
			if (find(opp[end]) == find(cur)){//already united
				cout << "NO";
				return 0;
			}
			unite(opp[end], cur);
			edges++;
		}
		endps.insert(opp[cur]);
	}
	//this means no cycles
	if (edges < N-1) cout << "NO";
	else cout << "YES";
}