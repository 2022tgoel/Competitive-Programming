/*
 * Each of Farmer John's N cows (1≤N≤2⋅105) has a favorite color. The cows are conveniently labeled 1…N (as always), and each color can be represented by an integer in the range 1…N.
There exist M pairs of cows (a,b) such that cow b admires cow a (1≤M≤2⋅105). It is possible that a=b, in which case a cow admires herself. For any color c, if cows x and y both admire a cow with favorite color c, then x and y share the same favorite color.

Given this information, determine an assignment of cows to favorite colors such that the number of distinct favorite colors among all cows is maximized. As there are multiple assignments that satisfy this property, output the lexicographically smallest one (meaning that you should take the assignment that minimizes the colors assigned to cows 1…N in that order).

INPUT FORMAT (file fcolor.in):
The first line contains N and M.
The next M lines each contain two space-separated integers a and b (1≤a,b≤N), denoting that cow b admires cow a. The same pair may appear more than once in the input.

OUTPUT FORMAT (file fcolor.out):
For each i in 1…N, output the color of cow i in the desired assignment on a new line.
SAMPLE INPUT:
9 12
1 2
4 2
5 8
4 6
6 9
2 9
8 7
8 3
7 1
9 4
3 5
3 4
SAMPLE OUTPUT:
1
2
3
1
1
2
3
2
3
*/

#include <bits/stdc++.h>
using namespace std;
const int MXN = 2*1e5+10;

int N, M, par[MXN];
vector<int> graph[MXN]; //all of the admirers
queue<int> q;
int find (int a){
	if (par[a]!=a){
		int x = find(par[a]);
		par[a] = x;
		return x;
	}
	else return a;
}

int main(){
	ifstream cin ("fcolor.in");
	ofstream cout ("fcolor.out");
	cin >> N >> M;
	for (int i = 1; i <=N; i++){
		par[i] = i;
	}
	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		if (graph[a].size() >= 2) q.push(a);
	}
	while (!q.empty()){
		int cur = q.front();
		if (graph[cur].size() <= 1) {
			q.pop();
			continue;
		}
		int a = graph[cur].back();
		graph[cur].pop_back();
		int b = graph[cur].back();
		//cout << cur << ' ' << a << ' ' << b << endl;
		//parents hold all the admirers of the merged cell
		//union function
		a=find(a);
		b = find(b);
		if (a == b) continue;
		else graph[cur].pop_back();
		if (graph[a].size() > graph[b].size()) swap(a, b); //one with more admirers is root
		par[a] = b;
		//
		//merge edges
		graph[b].insert(graph[b].end(), graph[a].begin(), graph[a].end());
		graph[a].clear();
		//
		graph[cur].push_back(b);
		if (graph[b].size() >=2) q.push(b);
	}
	map<int, int> comp;
	for (int i = 1; i <=N; i++){
		int cell=find(i);
		if (comp.count(cell) == 0){
			comp[cell] = static_cast<int>(comp.size());
		}
		cout << comp[cell] << endl;
	}
}
	
	
	
