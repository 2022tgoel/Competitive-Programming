#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+1;
const int MXQ = 2e5;
int N, Q;
int up[MXN][20]; // [x][y] -> go up 2^y edges from node x, where do you land
int main(){
	cin >> N >> Q;
	up[1][0] = 0; //-1
	for (int i = 2; i <=N; i++){
		int boss; cin >> boss;
		up[i][0] = boss;
	}
	for (int k = 1; k<=18;k++){
		//where you get if you go 2^k steps
		for (int i = 1; i <=N; i++){
			up[i][k] = up[up[i][k-1]][k-1];
		}
	}
	for (int i = 0;i <Q; i++){
		int x, k; cin >> x >> k;
		int cur = x;	
		for (int b = 0; b<=18;b++){
			if (k&(1<<b)){
				cur = up[cur][b];
			}
		}
		cout << ((cur==0) ? -1 : cur) << endl;
	}
}