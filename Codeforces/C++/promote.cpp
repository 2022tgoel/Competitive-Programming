/*
 * The cows have once again tried to form a startup company, failing to remember from past experience that cows make terrible managers!
The cows, conveniently numbered 1…N (1≤N≤100,000), organize the company as a tree, with cow 1 as the president (the root of the tree). Each cow except the president has a single manager (its "parent" in the tree). Each cow i has a distinct proficiency rating, p(i), which describes how good she is at her job. If cow i is an ancestor (e.g., a manager of a manager of a manager) of cow j, then we say j is a subordinate of i.

Unfortunately, the cows find that it is often the case that a manager has less proficiency than several of her subordinates, in which case the manager should consider promoting some of her subordinates. Your task is to help the cows figure out when this is happening. For each cow i in the company, please count the number of subordinates j where p(j)>p(i).

INPUT FORMAT (file promote.in):
The first line of input contains N.
The next N lines of input contain the proficiency ratings p(1)…p(N) for the cows. Each is a distinct integer in the range 1…1,000,000,000.

The next N−1 lines describe the manager (parent) for cows 2…N. Recall that cow 1 has no manager, being the president.

OUTPUT FORMAT (file promote.out):
Please print N lines of output. The ith line of output should tell the number of subordinates of cow i with higher proficiency than cow i.*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int N, a[MAXN], start[MAXN], last[MAXN], bit[2*MAXN], ans[MAXN];
vector<int> graph[MAXN];
vector<int> tour;
map<int, int> idx;

void upd(int ind){
	while (ind < 2*N){
		bit[ind]++;
		ind+=(ind&-ind);
	}
}
int qry(int ind){
	int ans = 0;
	while (ind > 0){
		ans+=bit[ind];
		ind-=(ind&-ind);
	}
	return ans;
}

void psh(int node){
	tour.push_back(node);
	int size = static_cast<int>(tour.size());
	if (start[node] == 0) start[node] = size;
	last[node] = size;
}

void DFS(int node){
	psh(node);
	for (int child : graph[node]) {
		if (start[child] != 0) continue;
		DFS(child);
		psh(node);
	}
}

int main(){
	ifstream cin ("promote.in");
	ofstream cout ("promote.out");
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> a[i];
		idx[a[i]] = i;
	}
	for (int i = 1; i < N; i++){
		int from;
		cin >> from;
		from--;
		graph[from].push_back(i);
	}
	DFS(0);
	sort(a, a+N, greater<int>());
	for(int i = 0; i < N; i++){
		int ind = idx[a[i]];
		ans[ind] = qry(last[ind]) - qry(start[ind]);
		upd(start[ind]);
	}
	for (int i = 0; i < N; i++){
		cout << ans[i] << endl;
	}
}
