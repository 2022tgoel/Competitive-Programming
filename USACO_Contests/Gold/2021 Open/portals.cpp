#include <bits/stdc++.h>
#define pii pair<int, int>
#define s second
#define f first
using namespace std;
const int MXN = 1e5+10;
int N;
int c[MXN];
vector<int> locs[2*MXN];
vector<int> edges[2*MXN];
int comp[2*MXN]; // component that node i is in
int viz[2*MXN];
void DFS(int num, int cur){
	viz[cur] = true;
	comp[locs[cur][0]] = num;
	comp[locs[cur][1]] = num;
	for(int edge : edges[cur]){
		if (viz[edge]) continue;
		DFS(num, edge);
	}
}
vector<pair<int, pii>> conedges; //edges of the connected components
int par[2*MXN];
int find(int x){
	if (par[x]==x) return x;
	int f = find(par[x]);
	par[x] = f;
	return f;
}
void un(int x, int y){
	x = find(x); y = find(y);
	par[x] = y;
}


int main(){
	cin >> N;
	for (int i = 1; i <=N; i++){ //2*i-1 and 2*i
		cin >> c[i];
		int a, b, c, d;
		cin >>a >> b >> c >> d;
		edges[a].push_back(b);
		edges[b].push_back(a);
		edges[c].push_back(d);
		edges[d].push_back(c);
		locs[a].push_back(2*i-1);
		locs[b].push_back(2*i-1);
		locs[c].push_back(2*i);
		locs[d].push_back(2*i);
	}
	int num = 1; //number of the curre connected component
	for (int i =1; i<=2*N; i++){
		if (viz[i]) continue;
		DFS(num, i);
		num++;
		/*
		cout << "component of each node" << endl;
		for (int i = 1; i <=2*N; i++){
			cout << comp[i] << endl;
		}
		cout << "status of each portal" << endl;
		for (int i =1; i <=2*N; i++) cout << viz[i] << endl;
		cout << endl;
		*/
	}
	
	
	for (int i =1; i <2*N; i+=2){
		int cA = comp[i]; int cB = comp[i+1];
		if (cA == cB) continue;
		int j = (i/2)+1;
		conedges.push_back(make_pair(c[j], make_pair(cA, cB)));
	}
	sort(conedges.begin(), conedges.end());
	for (int i= 1; i < num; i++) par[i] = i; 
	long cost = 0;
	int nedges = 0;
	for (auto edge : conedges){
		if (nedges == num-2) break;
		if (find(edge.s.f)!=find(edge.s.s)){
			un(edge.s.f, edge.s.s);
			nedges+=1;
			cost+=edge.f;
		}
		
	}
	cout << cost;
}