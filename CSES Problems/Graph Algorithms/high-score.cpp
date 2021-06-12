#include <bits/stdc++.h>
#define s second
#define f first
#define ll long long
using namespace std;
const int MXN = 2501;
const ll INF = MXN*1e9;
const int MXM = 5000;
int N, M;
ll dist[MXN];
pair<pair<int, int>, int> edges[MXM];
bool viz[MXN];
vector<int> adj[MXN];
bool canReach(int x){
	viz[x] = true;
	if (x == N) return true;
	bool b = false;
	for (int nxt : adj[x]) if (!viz[nxt]){
		b|=canReach(nxt);
	}
	return b;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	for (int i= 0 ;i < M; i++){
		cin >> edges[i].f.f >> edges[i].f.s >> edges[i].s;
		adj[edges[i].f.f].push_back(edges[i].f.s);
	}
	dist[1] = 0;
	for (int i = 2; i <=N;i++) dist[i] = -1*INF;
	for (int k = 0; k<N-1; k++){
		for (int i = 0; i< M;i++){
			int a = edges[i].f.f; int b = edges[i].f.s; int c = edges[i].s;
			if (dist[a]!=-1*INF) dist[b] = max(dist[b], dist[a] + c);
		}
	}
	for (int i = 0; i< M;i++){
		int a = edges[i].f.f; int b = edges[i].f.s; int c = edges[i].s;
		if (dist[a]+c > dist[b] && dist[a] != -1*INF){
			memset(viz, 0, sizeof(viz));
			if (canReach(b)) {
				cout << -1 << endl; return 0;
			}
		} 
	}
	cout << dist[N] << endl;
}