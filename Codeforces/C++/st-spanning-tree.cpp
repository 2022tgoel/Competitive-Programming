/*
time limit per test4 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an undirected connected graph consisting of n vertices and m edges. There are no loops and no multiple edges in the graph.

You are also given two distinct vertices s and t, and two values ds and dt. Your task is to build any spanning tree of the given graph (note that the graph is not weighted), such that the degree of the vertex s doesn't exceed ds, and the degree of the vertex t doesn't exceed dt, or determine, that there is no such spanning tree.

The spanning tree of the graph G is a subgraph which is a tree and contains all vertices of the graph G. In other words, it is a connected graph which contains n - 1 edges and can be obtained by removing some of the edges from G.

The degree of a vertex is the number of edges incident to this vertex.

Input
The first line of the input contains two integers n and m (2 ≤ n ≤ 200 000, 1 ≤ m ≤ min(400 000, n·(n - 1) / 2)) — the number of vertices and the number of edges in the graph.

The next m lines contain the descriptions of the graph's edges. Each of the lines contains two integers u and v (1 ≤ u, v ≤ n, u ≠ v) — the ends of the corresponding edge. It is guaranteed that the graph contains no loops and no multiple edges and that it is connected.

The last line contains four integers s, t, ds, dt (1 ≤ s, t ≤ n, s ≠ t, 1 ≤ ds, dt ≤ n - 1).

Output
If the answer doesn't exist print "No" (without quotes) in the only line of the output.

Otherwise, in the first line print "Yes" (without quotes). In the each of the next (n - 1) lines print two integers — the description of the edges of the spanning tree. Each of the edges of the spanning tree must be printed exactly once.

You can output edges in any order. You can output the ends of each edge in any order.

If there are several solutions, print any of them.
*/
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define s second
#define f first
const int MXN = 2e5+10;
int par[MXN], sz[MXN];
int n, m;
vector<pii> ans;
int find(int node){
	if (par[node] == node) return node;
	par[node] = find(par[node]);
	return par[node];
}
void join(int a, int b){
	int x = find(a);
	int y = find(b);
	if (sz[x] < sz[y]) swap(x, y);
	par[y] = x;
	sz[x]+=sz[y];
}
bool MSTworks(queue<pii>& q, int s, int ds, int t, int dt){
	vector<int> sEdge;
	vector<int> tEdge;
	while (!q.empty()){
		pii edge = q.front();q.pop();
		//cout << edge.f << edge.s << q.size() << endl;
		if (edge.f == s) {
			sEdge.push_back(edge.s); continue;
		}
		else if (edge.s == s){
			sEdge.push_back(edge.f); continue;
		}
		else if (edge.f == t){
			tEdge.push_back(edge.s); continue;
		}
		else if (edge.s == t){
			tEdge.push_back(edge.f); continue;
		}
		else {
			if  (find(edge.f)!=find(edge.s)){
				//cout << edge.f << edge.s << endl;
				join(edge.f, edge.s);
				ans.push_back(edge);
			}
		}
		
	}
	//tried all edges that are not s and t at this point
	set<int> compS;
	set<int> compT;
	for (int edge: sEdge) compS.insert(find(edge));
	for (int edge : tEdge) compT.insert(find(edge)); 
	for (int edge : sEdge){
		if (!compT.count(find(edge))) {
			if (edge==t) continue;
			join(s, edge);
			ans.push_back(make_pair(s, edge));
			ds--;
		}
	}
	for (int edge : tEdge){
		if (!compS.count(find(edge))) {
			join(t, edge);
			ans.push_back(make_pair(t, edge));
			dt--;
		}
	}
	if (ds < 0 || dt < 0) return false;
	for (int edge : sEdge){
		if (!(ds >0 && ans.size()< n-1)) break;
		if (find(edge)!=find(s)){
			//cout << edge << s <<  ans.size() << endl;
			join(s, edge);
			ans.push_back(make_pair(s, edge));
			ds--;
		}
	}
	for (int edge : tEdge){
		if (!(dt >0 && ans.size()< n-1)) break;
		if (find(edge)!=find(t)){
			//cout << edge << t << ans.size() << endl;
			join(t, edge);
			ans.push_back(make_pair(t, edge));
			dt--;
		}
	}
	return (ans.size() == n-1);

}

int main(){
	
	cin >> n >> m;
	queue<pii> edges;
	if (m < n-1) {
		cout << "No" << endl; exit(0);
	}
	for (int i = 1; i <= n; i++){
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edges.push(make_pair(a, b));
	}
	int s, ds, t, dt;
	cin >> s >> t >> ds >> dt;
	if (!MSTworks(edges, s, ds, t, dt)){
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
		for (pii edge : ans){
			cout << edge.f << ' ' << edge.s << endl;
		}
	}
}