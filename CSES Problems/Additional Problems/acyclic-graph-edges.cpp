#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+1;
multiset<int> edges[MXN];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		edges[a].insert(b);
		edges[b].insert(a);
	}
	for (int i =1; i<=n; i++){
		for (int e : edges[i]){
			edges[e].erase(i); //this one is used
			cout << i << ' ' << e << endl;
		}
	}
}