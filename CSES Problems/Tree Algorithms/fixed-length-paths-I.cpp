#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+10;
int N, K;
vector<int> adj[MXN];
int sz[MXN];
//
bool done[MXN]; //centroid is done being processed
long long ans = 0;
int cnt[MXN];

int calc_size(int cur, int par=0){
	if (done[cur]) return 0;
	sz[cur] = 1;
	for (int nxt : adj[cur]) if (nxt!=par){
		sz[cur]+=calc_size(nxt, cur);
	}
	return sz[cur];
}

int centroid(int cur, int comp_sz, int par=0){
	for (int nxt : adj[cur]) if (nxt!=par && !done[nxt]){
		if (sz[nxt]*2 > comp_sz) return centroid(nxt, comp_sz, cur);
	}
	return cur;
}

void qry(int cur, int par, int comp_sz, int d=1){
	if (d > K) return;
	if (done[cur]) return;
	if (K-d < comp_sz) ans+=cnt[K-d];
	for (int nxt : adj[cur]) if (nxt!=par){
		qry(nxt, cur, comp_sz, d+1);
	}
}

void upd(int cur, int par, int comp_sz, int d =1){
	if (d > K) return;
	if (done[cur]) return;
	cnt[d]++;
	for (int nxt : adj[cur]) if (nxt!=par){
		upd(nxt, cur, comp_sz, d+1);
	}
}

void calc_straddle(int c, int comp_sz){ //calc how many k path straddle the centriod
	cnt[0]++; //the root
	for (int nxt : adj[c]){
		qry(nxt, c, comp_sz);
		upd(nxt, c, comp_sz);
	}
}


void solve(int node){
	int comp_sz = calc_size(node);
	int c = centroid(node, comp_sz); //gets centroid of a subtree
	done[c] = true;
	fill(cnt, cnt+comp_sz, 0);
	calc_straddle(c, comp_sz);
	for (int nxt : adj[c]) if (!done[nxt]){
		solve(nxt);
	}
}

int main(){
	cin >> N >> K;
	for (int i= 0 ; i<N-1; i++){
		int a,b; cin >> a >> b;; adj[a].push_back(b); adj[b].push_back(a);
	}
	solve(1);
	cout << ans << endl;
}