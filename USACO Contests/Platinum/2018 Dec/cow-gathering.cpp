#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+10;
int N, M;
vector<int> adj[MXN];
int rng[MXN][2]; //the subtree range corresponding to the node
bool viz[MXN];
int id[MXN], ans[MXN], par[MXN];
int DFS(int cur, int l, int p=-1){
	viz[cur] = true;
	par[cur] = p;
	rng[cur][0] = l; //starts at l
	id[l] = cur; //time l->node cur
	for (int nxt : adj[cur]) if (!viz[nxt]) {
		l = DFS(nxt, l+1, cur);
	}
	rng[cur][1] = l;
	return l;
}
int right_before(int b, int a){
	//jump up till you get right before a
	int x =b;
	while (par[x]!=a) x = par[x];
	return x;
}
int bad[MXN];
int nxt[MXN];
int runId[MXN];
bool cycle_check(){
	int x = 0;
	for (int i =1; i<=N;i++) if (!runId[i]){
		runId[i] = ++x;
		int cur = i;
		while (nxt[cur]!=-1) {
			cur = nxt[cur];
			if (runId[cur] == x) return true;
			if (runId[cur]>0) break;
			runId[cur] = x;
		}
	}
	return false;
}
int main(){
	ifstream cin("gathering.in"); ofstream cout("gathering.out");
	cin >> N >> M;
	for (int i = 0; i < N-1;i++){
		int a,b; cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
	}
	int x = DFS(1, 0); //range should be 0..N-1
	assert(x==N-1);
	for (int i = 1; i<=N;i++) nxt[i] = -1;
	for (int i = 0; i < M;i++){
		int a,b; cin >> a >> b;
		nxt[a] = b;
		if (rng[a][0] < rng[b][0] && rng[b][0]<= rng[a][1]){
			//good segment ends at rng[b][1]
			//everything not b subtree is bad
			//child of a which includes b
			//start time greater that a
			//end time less that start time of b
			int x = right_before(b, a);
			bad[0]+=1; bad[rng[x][0]]-=1; bad[rng[x][1]+1]+=1;
		} 
		else {
			bad[rng[a][0]]+=1; bad[rng[a][1]+1]-=1;
		}
	}
	
	if (cycle_check()){
		for (int i =1; i<=N;i++) cout << 0 << endl;
		exit(0);
	}
	int running = 0;
	for (int i = 0; i<N;i++){
		running+=bad[i]; assert(running>=0);
		if (running==0){
			ans[id[i]] = 1;
		}
		else ans[id[i]] = 0;
	}
	for (int i = 1; i <=N;i++){
		cout << ans[i] << endl;
	}
}