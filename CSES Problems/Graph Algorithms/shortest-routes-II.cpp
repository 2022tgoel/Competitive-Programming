#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
const ll INF = 1e15;
const int MXN = 501;
int N, M, Q;
ll dist[MXN][MXN];
pair<pair<int,int>, ll> edges[MXN*MXN];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> Q;
	for (int i= 0; i < M;i++){
		cin >> edges[i].f.f >> edges[i].f.s >> edges[i].s;
	}
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <=N;j++){
			if (i==j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	for (int i = 0; i < M;i++){
		int a = edges[i].f.f; int b = edges[i].f.s; ll c = edges[i].s;
		dist[a][b] = min(c, dist[a][b]); dist[b][a] = min(c, dist[b][a]);
	}
	for (int k=1; k<=N;k++){
		for (int i=1;i<=N;i++){
			for (int j = 1; j<=N;j++){
				if (dist[i][j] > dist[i][k] + dist[j][k]){
					dist[i][j] = dist[i][k] + dist[j][k];
				}
			}
		}
	}
	for (int i= 0; i < Q; i++){
		int a, b; cin >> a >> b;
		if (dist[a][b] == INF) cout << -1 << endl;
		else cout << dist[a][b] << endl;
	}

}