#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+10;
const int MX = 1e9+1;
int N;
int a[MXN], v[MXN], viz[MXN];
int DFS(int x, int runId){
	//returns the last node it hits
	if (viz[x] > 0) return x;
	viz[x] =runId;
	return DFS(a[x], runId);
}

int minCycle(int node){
	int mn = v[node];
	int p = a[node];
	while (p!=node){
		mn = min(mn, v[p]);
		p = a[p];
	}
	return mn;
}

int main(){
	cin >> N;
	long long sum = 0;
	for (int i =1 ; i <= N; i++){
		cin >> a[i]  >> v[i];
		sum+=v[i];
	}
	int runId = 1;
	vector<int> cycleStarts;
	for (int i =1; i <=N; i++){
		if (viz[i]==0){
			int x = DFS(i, runId);
			if (runId == viz[x]){
				cycleStarts.push_back(x);
			}
			runId++;
		}

	}
	long long ans = sum;
	for (int node : cycleStarts){
		ans-=minCycle(node);
	}
	cout << ans;
}