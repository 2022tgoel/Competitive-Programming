#include <bits/stdc++.h>
using namespace std;
const int MXL = 501;
const int MXR = 501;
int L, R, K;
vector<int> adj[MXL];
int mt[MXR];
bool viz[MXL];
int find_aug(int cur){
	if (viz[cur]) return false;
	viz[cur] = true;
	for (int nxt : adj[cur]){
		if (mt[nxt] == -1 || find_aug(mt[nxt])){
			mt[nxt] = cur;
			return true;
		}
	}
	return false;
}
int main(){
	cin >> L >> R >> K;
	for (int i = 0; i < K; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	memset(mt, -1, sizeof(mt));
	int ans = 0;
	for (int i = 1; i <=L; i++){
		memset(viz, 0, sizeof(viz));
		ans+=find_aug(i);
	}
	cout << ans << endl;
	for (int i = 1; i <=R; i++){
		if (mt[i]!=-1) cout << mt[i] << ' ' << i << endl;
	}

}