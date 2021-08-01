#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+1;
int N;
vector<int> edges[MXN];
int f[MXN], h[MXN], g[MXN];
void DFS_in(int cur, int par=0){
	for (int e : edges[cur]) if (e!=par) {
		DFS_in(e, cur);
		h[cur] = max(h[cur], min(f[cur], f[e]+1));
		f[cur] = max(f[cur], f[e]+1);
	}
}
void DFS_out(int cur, int par=0){
	for (int e : edges[cur]) if (e!=par){
		if (f[e]+1 == f[cur]){
			g[e] = max(g[cur]+1, h[cur]+1);
		}
		else g[e] = max(g[cur]+1, f[cur]+1);
		DFS_out(e, cur);
	}
}
int main(){
	cin >> N;
	for (int i = 0; i < N-1; i++){
		int a, b; cin >> a >> b;
		edges[a].push_back(b); edges[b].push_back(a);
	}
	DFS_in(1);
	DFS_out(1);
	for (int i = 1; i <=N; i++){
		cout << max(f[i], g[i]) << ' ';
	}
}