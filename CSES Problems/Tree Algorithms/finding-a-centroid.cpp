#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+1;
int N, sz[MXN];
vector<int> adj[MXN];

void calc_sizes(int cur=1, int par=0) {
	sz[cur] = 1;
	for(int nxt : adj[cur]) if (par!=nxt){
		calc_sizes(nxt, cur);
		sz[cur] +=sz[nxt];
	}
}
int centroid(int cur=1, int par=0){
	for(int nxt : adj[cur]) if (par!=nxt){
		if (sz[nxt]*2 > N) return centroid(nxt, cur);
	}
	return cur;
}

int main(){
	ifstream cin("in.in");
	int a;
	cin >> N;
	for (int i= 0; i < N-1;i++){
		int a,b; cin >>a >> b; adj[a].push_back(b); adj[b].push_back(a);
	}
	calc_sizes();
	cout << centroid() << endl;
}