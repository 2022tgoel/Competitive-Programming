#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MXN = 501;
const ll INF = 1e13;
int N, M;
vector<int> adj[MXN];
ll cap[MXN][MXN]; //residual capacities

int par[MXN]; //solely used for the bfs
ll bfs(int s=1, int t=N){
	fill(begin(par), end(par), -1);
	queue<pair<int, ll>> q;
	q.push({s, INF});
	par[s]=-2;
	while(!q.empty()){
		int cur = q.front().first; ll flow = q.front().second; q.pop();
		for (int nxt : adj[cur]){
			if (par[nxt]!=-1 || cap[cur][nxt] == 0) continue;
			ll new_flow = min(flow, cap[cur][nxt]);
			par[nxt] = cur;
			if (nxt==t) return new_flow;
			q.push({nxt, new_flow});
		}
	}
	return 0;
}

ll` maxflow(int s=1, int t=N){
	ll flow = 0;
	ll new_flow = 0;
	while (new_flow=bfs(s, t)){
		flow+=new_flow;
		int cur = t;
		while (cur!=s){
			int prev = par[cur];
			cap[prev][cur] -= new_flow;
			cap[cur][prev] += new_flow;
			cur = prev;
		}
	}
	return flow;
}
int main(){
	cin >> N >> M;
	for (int i=0; i < M; i++){
		int a, b, c; cin >> a >> b >> c; adj[a].push_back(b), adj[b].push_back(a);
		cap[a][b] += c;
	}
	cout << maxflow() << endl;
}