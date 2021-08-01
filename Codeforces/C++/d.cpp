/*
You are given an undirected unweighted graph consisting of n vertices and m edges (which represents the map of Bertown) and the array of prices p of length m. It is guaranteed that there is a path between each pair of vertices (districts).

Mike has planned a trip from the vertex (district) a to the vertex (district) b and then from the vertex (district) b to the vertex (district) c. He can visit the same district twice or more. But there is one issue: authorities of the city want to set a price for using the road so if someone goes along the road then he should pay the price corresponding to this road (he pays each time he goes along the road). The list of prices that will be used p is ready and they just want to distribute it between all roads in the town in such a way that each price from the array corresponds to exactly one road.

You are a good friend of Mike (and suddenly a mayor of Bertown) and want to help him to make his trip as cheap as possible. So, your task is to distribute prices between roads in such a way that if Mike chooses the optimal path then the price of the trip is the minimum possible. Note that you cannot rearrange prices after the start of the trip.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

The first line of the test case contains five integers n,m,a,b and c (2≤n≤2⋅105, n−1≤m≤min(n(n−1)2,2⋅105), 1≤a,b,c≤n) — the number of vertices, the number of edges and districts in Mike's trip.

The second line of the test case contains m integers p1,p2,…,pm (1≤pi≤109), where pi is the i-th price from the array.

The following m lines of the test case denote edges: edge i is represented by a pair of integers vi, ui (1≤vi,ui≤n, ui≠vi), which are the indices of vertices connected by the edge. There are no loops or multiple edges in the given graph, i. e. for each pair (vi,ui) there are no other pairs (vi,ui) or (ui,vi) in the array of edges, and for each pair (vi,ui) the condition vi≠ui is satisfied. It is guaranteed that the given graph is connected.

It is guaranteed that the sum of n (as well as the sum of m) does not exceed 2⋅105 (∑n≤2⋅105, ∑m≤2⋅105).

Output
For each test case, print the answer — the minimum possible price of Mike's trip if you distribute prices between edges optimally.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <fstream>
#include <utility>
#include <deque>
#include <algorithm>
#define pii pair<int, int>
#define s second
#define f first
using namespace std;
const int MAXN = 2e5+10;
int t, n, m, a, b, c;

void BFS(int src, vector<vector<int>>& graph, vector<int>& d){
	queue<int> q;
	
	for (int i = 0; i <= n; i++) d[i] = -1;
	q.push(src);
	d[src] = 0;
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (int edge : graph[cur]) {
			if (d[edge]==-1) {
				d[edge] = d[cur]+1;
				q.push(edge);
			}
		}
	}
}

int main(){
	//ifstream cin ("d.in");
	//ofstream cout ("d.out");
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> n >> m >> a >> b >> c;
		vector<long long> p(m+1);
		vector<int> d1(n+1), d2(n+1), d3(n+1);
		vector<vector<int>> graph(n+1);
		for (int i = 1; i <= m ;i++) cin >> p[i];
		p[0] = 0;
		sort(p.begin(), p.end());
		for (int i = 1; i<= m; i++) {
			p[i] = p[i-1] + p[i];
		}
		
		for (int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		BFS(a, graph, d1);
		BFS(b, graph, d2);
		BFS(c, graph, d3);
		
		long long ans = 1e18;
		for (int i = 1; i <=n; i++){
			if (d1[i] + d2[i] + d3[i] > m) continue;
			ans = min(ans, p[d2[i]] + p[d2[i] + d1[i] + d3[i]]);
		}
		cout << ans << endl;
	}
}