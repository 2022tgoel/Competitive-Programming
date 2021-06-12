#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+1;
int sub[MXN];
vector<int> child[MXN];
bool viz[MXN];
int DFS(int cur){
	viz[cur] = true;
	sub[cur]=1;
	for (int c : child[cur]){
		assert(viz[c] == false);
		sub[cur]+=DFS(c);
	}
	return sub[cur];
}
int main(){
	int n; cin >> n;
	for (int i = 2; i <= n; i++){
		int b; cin >> b;
		child[b].push_back(i);
	}
	DFS(1);
	for (int i = 1; i <=n; i++){
		cout << (sub[i] - 1) << ' ';
	}
}