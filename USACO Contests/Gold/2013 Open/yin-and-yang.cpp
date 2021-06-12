#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int MXN = 1e5+1;
int N, val[MXN];
vector<pair<int,int>> adj[MXN];
map<int,int> cnt;

int calc_val(int cur, int pref, int par=0){
	val[cur] = pref;
	cnt[pref]++;
	for (pair<int,int> edge : adj[cur]) {
		if (edge.f!=par) calc_val(edge.f, pref+edge.s, cur);
	}
}

map<int,int> sub_cnt[MXN]; //subtree counts;
long long ans = 0;

void solve(int cur, int par=0){
	int add;
	for (auto edge : adj[cur]) if (edge.f!=par){
		int nxt = edge.f;
		solve(nxt, cur);
		add = sub_cnt[nxt][val[cur]];
		if (add > 0) ans+=(add-1); //inside the subtree
		//merge map
		if (sub_cnt[cur].size() < sub_cnt[nxt].size()) swap(sub_cnt[cur], sub_cnt[nxt]);
		for (pair<int,int> v : sub_cnt[nxt]){
			sub_cnt[cur][v.f]+=v.s;
		}
		sub_cnt[nxt].clear();
	}
	sub_cnt[cur][val[cur]]++;
}

int main(){
	cin >> N;
	for(int i= 0; i <N-1;i++){
		int a, b, c; cin >> a >> b >> c;
		c = (c==0 ? -1 : 1);
		adj[a].push_back({b, c}); adj[b].push_back({a, c});
	}
	int root = 1;
	for (int i = 1; i <=N;i++){
		if (adj[i].size()==1) {
			root = i; break;
		}
	}
	assert(root!=1 || adj[1].size()==0);
	cout << root << endl;
	calc_val(root, 0);
	for (int i= 1; i <=N;i++) cout << val[i] << endl;
	solve(root);
	cout << ans << endl;
}