#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5;
int N;
vector<int> edges[MXN];
int p[MXN];
int mn[MXN];
int mx[MXN];
bool viz[MXN];
map<pair<int, int>, int> mp;
void calc(int x, int y){ //think y-->x
	int id = mp[make_pair(x, y)];
	if (viz[id]) return;
	viz[id] = true;
	for (int e : edges[x]) if (e!=y){
		calc(e, x);
		int nid = mp[make_pair(e, x)];
		mx[id] = max(mx[id], mx[nid] + p[x]);
		mx[id] = max(mx[id], p[x]);
		mn[id] = min(mn[id], mn[nid] + p[x]);
		mn[id] = min(mn[id], p[x]);
	}
	if (edges[x].size() == 1) {
		//is a leaf
		mx[id] = p[x]; mn[id] = p[x];
	}

}

void calcNode(int x, int par=0){
	//requirement - all the outward edges are correctly calculated
	int Fmx = 0;
	int Smx = 0;
	int Fmn = 0;
	int Smn = 0;
	for (int e : edges[x]){
		int id = mp[make_pair(e, x)];
		Smx = max(Smx, min(mx[id], Fmx));
		Fmx = max(mx[id], Fmx);
		Smn = min(Smn, max(mn[id], Fmn));
		Fmn = min(Fmn, mn[id]);
	}
	for (int e : edges[x]) {
		int id = mp[make_pair(e, x)];
		int nid = mp[make_pair(x, e)];
		if (Fmx == mx[id]){
			mx[nid] = Smx + p[x];
		} else mx[nid] = Fmx + p[x];
		if (Fmn == mn[id]){
			mn[nid] = Smn + p[x];
		} else mn[nid] = Fmn + p[x];
	}
	//now you have calculated all the edges incident... you can move to an adjacent node
	for (int e : edges[x]) if (e!=par){
		calcNode(e, x);
	}
}

int main(){
	ifstream cin("btree.in");
	ofstream cout("btree.out");
	cin >> N;
	int id = 0;
	for (int i = 2; i <=N;i++){
		int j; cin >> j;
		edges[i].push_back(j);
		edges[j].push_back(i);
		mp[make_pair(i, j)] = id++;
		mp[make_pair(j, i)] = id++;
	}
	for (int i =1; i <=N;i++){
		char c; cin >> c;
		if (c=='(') p[i] = 1;
		else p[i] = -1;
	}
	for (int e : edges[1]){
		calc(e, 1);
	}
	calcNode(1);
	int ans = 0;
	for (int i = 1; i <=N; i++){
		for (int j : edges[i]){
			int x = mp[make_pair(i, j)];
			int y = mp[make_pair(j, i)];
			ans = max(ans, min(mx[x], -1*mn[y]));
		}
	}
	cout << ans << endl;
}