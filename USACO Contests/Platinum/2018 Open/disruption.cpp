/*
Farmer John prides himself on running a well-connected farm. The farm is a collection of N pastures (2≤N≤50,000), pairs of which are connected with N−1 bi-directional pathways, each having unit length. Farmer John notices that using an appropriate series of these pathways, it is possible to travel from any pasture to any other pasture.
Although FJ's farm is connected, he worries what might happen if one of the pathways gets blocked, as this would effectively partition his farm into two disjoint sets of pastures, where the cows could travel within each set but not between the sets. FJ therefore builds a set of M additional bi-directional pathways (1≤M≤50,000), each with a positive integer length at most 109. The cows still only use the original pathways for transit, unless one of these becomes blocked.

If one of the original pathways becomes blocked, the farm becomes partitioned into two disjoint pieces, and FJ will select from among his extra pathways a single replacement pathway that re-establishes connectivity between these two pieces, so the cows can once again travel from any pasture to any other pasture.

For each of the original pathways on the farm, help FJ select the shortest suitable replacement pathway.

INPUT FORMAT (file disrupt.in):
The first line of input contains N and M. Each of the next N−1 lines describes an original pathway using integers p, q, where p≠q are the pastures connected by the pathway (in the range 1…N). The remaining M lines each describe an extra pathway in terms of three integers: p, q, and r, where r is the length of the pathway. At most one pathway runs between any pair of pastures.
OUTPUT FORMAT (file disrupt.out):
For each of the N−1 original pathways in the order they appear in the input, output the length of the shortest suitable replacement pathway which would re-connect the farm if that original pathway were to be blocked. If no suitable replacement exists, output -1.
SAMPLE INPUT:
6 3
1 2
1 3
4 1
4 5
6 5
2 3 7
3 6 8
6 4 5
SAMPLE OUTPUT:
7
7
8
5
5
Problem credits: Brian Dean
*/
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int MXN = 5e5;
int N, M;
vector<pair<int, int>> adj[MXN];
vector<pair<int, int>> rep[MXN];
int ans[MXN];
set<pair<int, int>> edges[MXN];
void DFS(int cur, int ind=-1, int par=0){  //ind is index of the edge associated with that node
	//merge all child sets
	for (pair<int, int> i : adj[cur]) {
		if (i.f==par) continue;
		DFS(i.f, i.s, cur);
		if (edges[cur].size() < edges[i.f].size()) swap(edges[cur], edges[i.f]);
		for (pair<int,int> edge : edges[i.f]) {
			if (edges[cur].count(edge)) edges[cur].erase(edge);
			else edges[cur].insert(edge);
		}
	}
	//remove all edges to a child
	for (pair<int,int> r : rep[cur]){
		if (edges[cur].count(r)) edges[cur].erase(r);
		else edges[cur].insert(r);
	}
	if(ind==-1) return;
	if (edges[cur].size()==0) ans[ind] = -1;
	else ans[ind] = (*edges[cur].begin()).f;
}

int main(){
	ifstream cin("disrupt.in"); ofstream cout("disrupt.out");
	cin >> N >> M;
	for (int i = 0; i < N-1; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back({b, i}); adj[b].push_back({a, i});
	}
	for (int i = 0; i < M; i++){
		int a, b, c; cin >> a >> b >> c;
		rep[a].push_back({c, i}); rep[b].push_back({c, i});
	}
	DFS(1);
	for(int i = 0; i<N-1; i++){
		cout << ans[i] << endl;
	}
}