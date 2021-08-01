#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int MXN = 510;
const int INF = 1e8;
const int MXM = 1000;
int N, M;
int cap[MXN][MXN]; //capacity from i to j
vector<int> adj[MXN];
int par[MXN]; //parents in aug path
int edges[MXM][2];

int find_aug_path(){
	fill(begin(par), end(par), -1);
	queue<pair<int, int>> q;
	q.push({1, INF}); par[1] = -2;
	while(!q.empty()){
		int cur = q.front().f; int flow = q.front().s; q.pop();
		for (int nxt : adj[cur]){
			if (par[nxt]!=-1 || cap[cur][nxt] <= 0) continue;
			par[nxt] = cur;
			int new_flow = min(flow, cap[cur][nxt]);
			if (nxt == N) return new_flow;
			q.push({nxt, new_flow}); 
		}
	}
	return 0;

}

int maxflow(){
	int ans = 0;
	int flow = 0;
	while (flow=find_aug_path()){
		ans+=flow;
		int cur = N;
		while (cur!=1){
			cap[par[cur]][cur] -= flow;
			cap[cur][par[cur]] +=flow;
			cur = par[cur];
		}
	}
	return ans;
}

int DFS(int cur){
	//par is now being used as a traditional visited array
	par[cur] =1;
	for (int i : adj[cur]){
		if (cap[cur][i] >0 && !par[i]) DFS(i);
	}
}

int main(){
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int a, b; cin >> a >> b;
		cap[a][b] = 1; cap[b][a] = 1; adj[a].push_back(b); adj[b].push_back(a);
		edges[i][0] = a; edges[i][1] = b;
	}
	int mf = maxflow();
	fill(begin(par), end(par), 0);
	DFS(1);
	int num = 0;
	for (int i = 0; i < M; i++){
		int a = edges[i][0]; int b = edges[i][1];
		if (par[a]!=par[b]) num++;
	}
	cout << num << endl;
	for (int i = 0; i < M; i++){
		int a = edges[i][0]; int b = edges[i][1];
		if (par[a]!=par[b]) cout << a <<' ' << b << endl;
	}
}