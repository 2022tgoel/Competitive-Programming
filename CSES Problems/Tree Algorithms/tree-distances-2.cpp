#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+1;
int N; 
vector<int> edges[MXN];
int in[MXN], d[MXN];
long long ans[MXN];
int dfs1(int cur, int dist=0, int par=0){
	d[cur] =dist;
	in[cur] = 1;
	for (int e : edges[cur]) if (e!=par){
		in[cur]+=dfs1(e, dist+1, cur);
	}
	return in[cur];
}
void dfs2(int cur, long long a, int par=0){
	ans[cur] = a;
	for (int e : edges[cur]) if (e!=par){
		dfs2(e, a+N-2*(in[e]), cur);
	}
}
int main(){
	cin >> N;
	for (int i = 0; i < N-1; i++){
		int a, b; cin >> a >> b;
		edges[a].push_back(b); edges[b].push_back(a);
	}
	int x = dfs1(1);
	assert(x==N);
	long long a = 0;
	for (int i =1; i<=N;i++){
		a+=d[i];
	}
	dfs2(1, a);
	for (int i = 1; i<=N; i++){
		cout << ans[i] << ' ' ;
	}
}