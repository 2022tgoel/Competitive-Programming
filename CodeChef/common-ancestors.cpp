#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e6+10;
int T, N;
vector<int> g1[MXN], g2[MXN];
int d1[MXN], d2[MXN];


int b_graph(vector<int> *g){
	int root = 0;
	for (int i = 1; i <= N; i++){
		int par; cin >> par;
		if (par!=-1) g[par].push_back(i);
		else root = i;
	}
	return root;
}

void c_depth(int cur, vector<vector<int>>& g, vector<int>& d, int par = 0){
	d[cur] = d[par]+1;
	for (int nxt : g[cur]) if (nxt!=par){
		if (){
			
		}
	}
}

int main(){
	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> N;
		int r1 = b_graph(g1);
		int r2 = b_graph(g2);
		c_depth(r1, g2, d1);
		c_depth(r2, g2, d2);
		fill_n(g1, N+1, vector<int>());
		fill_n(g2, N+1, vector<int>());
		fill_n(d1, N+1, 0);
		fill_n(d2, N+1, 0);
	}
}