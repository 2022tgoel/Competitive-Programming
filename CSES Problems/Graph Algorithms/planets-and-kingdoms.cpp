#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+10;
int N, M, ind[MXN], lowlink[MXN], comp[MXN];
bool on[MXN];
int I = 1;
int C = 1;
vector<int> G[MXN];
deque<int> S;

int DFS(int node){
	ind[node] = I++;
	lowlink[node] = ind[node];
	S.push_back(node);
	on[node] = true;
	for (int nxt : G[node]){
		if (on[nxt]){
			lowlink[node] = min(lowlink[node], ind[nxt]);
		}
		else if (!ind[nxt]){
			lowlink[node] = min(lowlink[node], DFS(nxt));
		}
	}

	if (lowlink[node] == ind[node]){
		while (S.back() != node){
			int x = S.back();
			comp[x] = C;
			S.pop_back();
			on[x] = false;
		}
		comp[node] = C; S.pop_back();
		on[node] = false;
		C++;
	}

	return lowlink[node];

}

void tarjan(){
	for (int i = 1; i <= N; i++){
		if (!ind[i]) DFS(i);
	}
}

int main(){
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int a,b; cin >> a >> b;
		G[a].push_back(b);
	}
	tarjan();
	cout << C-1 << endl;
	for (int i = 1; i <= N; i++){
		cout << comp[i] << ' ' ;
	}
}