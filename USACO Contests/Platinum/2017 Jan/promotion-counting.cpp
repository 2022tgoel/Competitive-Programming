//apparently this was a resolve? should find the other solution file
#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+10;
int N;
pair<int, int> p[MXN];
int r[MXN][2], ans[MXN], bit[MXN];
vector<int> ch[MXN];
vector<int> range;
void DFS(int cur){
	r[cur][0] = range.size();
	range.push_back(cur);
	for (int child : ch[cur]) {
		DFS(child);
	}
	r[cur][1] = range.size()-1;
}
void upd(int ind){
	while (ind<=N){
		bit[ind]+=1;
		ind+=(ind&-ind);
	}
}
int qry(int ind){
	int ans = 0;
	while (ind>0){
		ans+=bit[ind];
		ind-=(ind&-ind);
	}
	return ans;
}

int main(){
	ifstream cin("promote.in"); ofstream cout ("promote.out");
	cin >> N;
	for (int i = 1; i <=N; i++) {
		int val; cin >> val;
		p[i] = make_pair(val, i);
	}
	sort(p+1, p+N+1, greater<pair<int, int>>());
	for (int i = 2; i<=N; i++){
		int a; cin >> a; ch[a].push_back(i);
	}
	range.push_back(0); //filler element
	DFS(1);
	for (int i = 1; i <=N; i++){
		int node = p[i].second;
		ans[node] = qry(r[node][1]) - qry(r[node][0]);
		upd(r[node][0]);
	}
	for (int i =1; i <=N; i++) cout << ans[i] << endl;
}