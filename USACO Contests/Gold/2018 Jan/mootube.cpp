#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int> 
#define f first
#define s second
const int MXN = 1e5 +10;
int N, Q;
pair<pair<int, int>, int> edges[MXN], q[MXN];
int par[MXN];
int ans[MXN];
bool compareEdge(const pair<pii, int>& a, const pair<pii, int>& b){
	return a.s > b.s;
}
bool compareQ(const pair<pii, int> & a, const pair<pii, int> & b){
	return a.f.f > b.f.f;
}
int find(int node){
	if (par[node] < 0) return node;
	else {
		int p = find(par[node]);
		par[node] = p;
		return p;
	}
}
int join(int a, int b){
	int x = find(a);
	int y = find(b);
	if (par[x] > par[y]) swap(x, y); // make x the bigger one
	par[x] += par[y];
	par[y] = x;
}

int main(){
	ifstream cin ("mootube.in");
	ofstream cout ("mootube.out");
	cin >> N >> Q;
	for (int i = 1; i <=N; i++) par[i] = -1;
	for (int i = 0; i < N-1; i++){
		cin >> edges[i].f.f >> edges[i].f.s >> edges[i].s;
	}
	for (int i = 0; i < Q; i++){
		cin >> q[i].f.f >> q[i].f.s;
		q[i].s = i; //orginal index
	}
	sort(edges, edges+N-1, compareEdge);
	sort(q, q+Q, compareQ);
	int cur = 0;
	for (int i = 0; i < Q; i++){
		int mink = q[i].f.f;
		while (cur < N-1 && edges[cur].s >= mink){
			join(edges[cur].f.f, edges[cur].f.s);
			cur++;
		}
		ans[q[i].s] = -1*par[find(q[i].f.s)];
	}
	for (int i = 0; i < Q; i++){
		cout << ans[i]-1 << endl;
	}
}