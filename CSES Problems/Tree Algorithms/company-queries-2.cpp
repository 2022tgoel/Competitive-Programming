#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+1;
const int MXQ = 2e5;
int N, Q;
int up[MXN][20]; // [x][y] -> go up 2^y edges from node x, where do you land
vector<int> down[MXN];
int depth[MXN];
int upk(int x, int k){
	int cur = x;	
	for (int b = 0; b<=18;b++){
		if (k&(1<<b)){
			cur = up[cur][b];
		}
	}
	return cur;
}
int lca(int x, int y){
	int k = depth[x] - depth[y];
	if (k > 0) x = upk(x, k);
	else y = upk(y, -1*k);
	if (x==y) return x;
	int c1 = x; int c2 = y;
	for (int b = 18; b>=0; b--){
		if (up[c1][b] != up[c2][b]){
			c1 = up[c1][b];
			c2 = up[c2][b];
		}
	}
	return up[c1][0];
}

void DFS(int x, int d){
	depth[x] =d;
	for (int c : down[x]){
		if (depth[c] == 0){
			DFS(c, d+1);
		}
	}
}

int main(){
	cin >> N >> Q;
	up[1][0] = 0; //-1
	for (int i = 2; i <=N; i++){
		int boss; cin >> boss;
		up[i][0] = boss;
		down[boss].push_back(i);
	}
	DFS(1, 1);
	for (int k = 1; k<=18;k++){
		//where you get if you go 2^k steps
		for (int i = 1; i <=N; i++){
			up[i][k] = up[up[i][k-1]][k-1];
		}
	}
	for (int i = 0;i <Q; i++){
		int x, y; cin >> x >> y;
		cout << lca(x, y) << endl;
	}
}