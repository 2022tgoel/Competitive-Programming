#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int MXN = 5e4+10;
int T, N, K;
int t[MXN], x[MXN], w[MXN];
set<pair<int, int>, greater<pair<int,int>>> graph[MXN];
int mt[MXN];
bool viz[MXN];
set<pair<int,int>> lefts; // left nodes (guersneys)
bool find_aug(int cur){ //guersney
	if (viz[cur]) return false;
	viz[cur] = true;
	for (pair<int, int> node : graph[cur]){
		int to = node.second;
		if (mt[to] ==-1 || find_aug(mt[to])){
			mt[to] = cur;
			return true;
		}
	}
	return false;
}

int main(){
	cin >> T >> N >> K;
	if (T == 2){
		cout << 0 << endl;
		exit(0);
	}
	int ans = 0;
	for (int i = 0; i < N; i++){
		char type; int a, b;
		cin >> type >> a >> b;
		x[i] = a; w[i] = b;
		ans+=w[i];
		if (type == 'G') {
			t[i] = 0;
			lefts.insert({w[i], i});
		}
		else t[i] = 1;
		
	}
	for (int i = 0; i < N; i++){
		for (int j = i+1; (j<N && x[j] - x[i] <= K); j++){
			if (t[i]!=t[j]){ //make edge
				graph[i].insert({w[j], j});
				graph[j].insert({w[i], i});
			}
		}
	}
	for (int i = 0; i < N; i++){
		mt[i] = -1;
	}

	for (pii a : lefts){
		int i = a.second;
		for (pii b : lefts){
			int j = b.second;
			viz[j] = false;
		}
		find_aug(i);
	}
	for (int i = 0; i <N; i++){
		if (mt[i]!=-1) {
			ans -= w[i];
			ans -= w[mt[i]];
		}
	}
	cout << ans << endl;
}