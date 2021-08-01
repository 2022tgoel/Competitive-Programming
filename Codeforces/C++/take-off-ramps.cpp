//https://codeforces.com/problemset/problem/141/D

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define s second
#define f first
#define mp make_pair
#define int long long 
set<int> locs;
map<int, vector<pii>> graph;
map<int, int> d;
map<int, int> prv;
map<pair<pii, int>, int> ramps;
int n, L;

void dijkstra(){
	set<pii> q;
	for (auto node : graph) d[node.f] = 1e18;
	d[L] = 1e18;
	d[0] = 0;
	prv[0] = -1;
	q.insert(mp(d[0] , 0));
	while (!q.empty()){
		pii cur = *q.begin(); q.erase(cur);
		int dist = cur.f; int node = cur.s;
		for (pii edge : graph[node]){
			int child = edge.f; int w = edge.s;
			if (dist + w < d[child]){
				q.erase(mp(d[child], child));
				d[child] = dist + w;
				prv[child] = node;
				q.insert(mp(d[child], child));
			}
		}
	}
}

void print_ans(){
	cout << d[L] << endl;
	vector<int> u;
	int x = L;
	while (prv[x]!=-1){
		int p = prv[x];
		auto a = mp(mp(p, x), d[x] - d[p]);
		if (ramps.count(a)) u.push_back(ramps[a]); //such a distance only possible it the ramp was used
		x = p;
	}
	reverse(u.begin(), u.end());
	cout << u.size() << endl;
	for (int i = 0; i < u.size(); i++){
		cout << u[i] << endl;
	}
}

main(){
	cin >> n >> L;
	for (int i = 0; i < n;i++){
		int xi, di, ti, pi;
		cin >> xi >> di >> ti >> pi;
		int start = xi-pi; int end = xi+di; int time = pi + ti;
		if (start < 0) continue;
		locs.insert(start); locs.insert(end);
		graph[start].push_back(make_pair(end, time));
		ramps[mp(mp(start, end), time)] = i+1;
	}
	locs.insert(0); locs.insert(L);
	while (locs.size() > 1){
		int a = *locs.begin(); locs.erase(a); int b = *locs.begin();
		graph[a].push_back(mp(b, b-a)); graph[b].push_back(mp(a, b-a));
	}
	dijkstra();

	print_ans();
}