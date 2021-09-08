#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int MXN = 1e5+10;
int N, M, C, tim[MXN];
vector<pii> graph[MXN];
set<int> parents[MXN];
int main(){
	ifstream cin ("timeline.in");
	ofstream cout ("timeline.out");
	cin >> N >> M >> C;
	for (int i = 1; i <= N; i++){
		cin >> tim[i];
	}
	for (int i = 0; i < C; i++){
		int p, c, t;
		cin >> p >> c >> t;
		graph[p].push_back(make_pair(c, t));
		parents[c].insert(p);
	}
	queue<int> q;
	for (int i = 1; i <=N;i++){
		if (parents[i].size() == 0) q.push(i);
	}
	while (!q.empty()){
		int cur = q.front(); q.pop();
		for (pii p : graph[cur]){
			int child = p.first;
			tim[child] = max(tim[child], tim[cur] + p.second);
			parents[child].erase(cur);
			if (parents[child].size() == 0) q.push(child);
		}
	}
	for (int i = 1; i <=N;i++) cout << tim[i] << endl;
}