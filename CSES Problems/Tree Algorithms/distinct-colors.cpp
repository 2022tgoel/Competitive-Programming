#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+1;
int N, col[MXN], ans[MXN];
vector<int> adj[MXN];
set<int> sets[MXN];

void DFS(int cur, int par=0){
	for (int nxt : adj[cur]) if (nxt!=par){
		DFS(nxt, cur);
		if (sets[cur].size() < sets[nxt].size()) swap(sets[cur], sets[nxt]);
		for (int elem : sets[nxt]) sets[cur].insert(elem);
		sets[nxt].clear();
	}
	sets[cur].insert(col[cur]);
	ans[cur] = sets[cur].size();
	return;
}

int main(){
	cin >> N;
	for (int i =1; i<=N;i++){
		cin >> col[i];
	}
	for (int i = 0; i < N-1; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	DFS(1);
	for (int i= 1; i <=N;i++) cout << ans[i] << ' ';
}