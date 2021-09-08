#include <bits/stdc++.h>
#define pii pair<int, int>
#define s second
#define f first
using namespace std;
int n, k;
const int MX = 2e9;
const int MXN = 5e4+20;
int b[MXN], dist[MXN];
set<int> locs[60];
vector<int> edges[MXN];
vector<int> gb[60];
bool v[MXN];
int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		locs[b[i]].insert(i);
	}
	for(int i =1; i <= k; i++){
		for (int j = 1; j<=k; j++){
			char c; cin >> c;
			if (c=='1') gb[i].push_back(j);
		}	
	}
	for (int i = 0; i<n; i++){
		for (int breed : gb[b[i]]){
			if (breed == b[i]) continue;
			auto af = locs[breed].lower_bound(i);
			if (af != locs[breed].end()){
				edges[i].push_back(*af);
				//cout << i << ' ' << *af << endl;
				assert(*af!=i);
			}
			if (af !=locs[breed].begin()){
				edges[i].push_back(*(--af));
				//cout << i << ' ' << *(--af) << endl;
			}
			if (breed == b[n-1]){
				edges[i].push_back(n-1);
			}
		}
	}
	set<pii> q;
	for (int i = 1; i < n; i++){
		q.insert(make_pair(MX, i));
		dist[i] = MX; v[i] = false;
	} 
	q.insert(make_pair(0, 0)); //0 distance to get to loc 0
	dist[0] = 0;
	while (q.size()){
		//cout << "here" << endl;
		pii cur = *q.begin(); 
		//cout << cur.s << ' ' << cur.f << endl;
		v[cur.s] = true;
		q.erase(cur);
		//cout << cur.s << endl;
		for (int edge : edges[cur.s]){
			if (!v[edge]){
				int d = dist[cur.s] + abs(edge-cur.s);
				//cout << edge << d << endl;
				if (d < dist[edge]){
					q.erase(make_pair(dist[edge], edge));
					dist[edge] = d;
					//cout << edge << d << dist[edge] << endl;
					q.insert(make_pair(dist[edge], edge));
				}	
			}
		}
		//cout << q.size();
	}

	int ans = dist[n-1];
	/*
	for (int i : locs[b[n-1]]){
		ans = min(ans, dist[i] +n-1-i);
	}*/
	cout << (ans == MX ? -1 : ans) << endl;
}