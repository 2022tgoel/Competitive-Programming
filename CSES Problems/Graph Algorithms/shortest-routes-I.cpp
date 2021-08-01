#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
const ll INF = 1e15;
const int MXN = 1e5+10;
int N, M;
vector<pair<int,int>> adj[MXN];
ll dist[MXN];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i= 0; i < M; i++){
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}

	//Run Dijkstra's
	set<pair<ll, int>> q;
	for (int i = 2; i<=N;i++){
		q.insert({INF, i}); dist[i] = INF;
	}
	q.insert({0, 1}); dist[1] = 0;
	while (q.size()){
		pair<ll,int> cur = *q.begin(); q.erase(cur);
		ll cost = cur.f; int node = cur.s;
		for (pair<int, int> e : adj[node]){
			if (cost + e.s < dist[e.f]){
				//found a better path, update the queue
				q.erase({dist[e.f], e.f});
				dist[e.f] = cost + e.s;
				q.insert({dist[e.f], e.f});
			}
		}
	}
	for (int i = 1; i <=N;i++) cout << dist[i] << ' ' ;
}