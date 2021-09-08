#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define f first
#define s second
const int MXP = 1e5+50;
int N, P;
pii pts[MXP][2];

struct X_Compare {
	bool operator() (int a, int b){
		if (pts[a][0].f < pts[b][0].f) return true;
		else if (pts[a][0].f == pts[b][0].f) return pts[a][0].s < pts[b][0].s;
		else return false;
	}
} x_comp;

struct Y_Compare {
	bool operator() (int a, int b){
		if (pts[a][0].s < pts[b][0].s) return true;
		else if (pts[a][0].s == pts[b][0].s) return pts[a][0].f < pts[b][0].f;
		else return false;
	}
} y_comp;

set<int, X_Compare> x_sort;
set<int, Y_Compare> y_sort;
vector<pii> graph; 

int dist(int i, int j){
	pii a = pts[i][1];
	pii b = pts[j][0];
	return b.f - a.f + b.s - 
}

int main(){
	cin >> N >> P;
	pts[0][0] = make_pair(0, 0);
	pts[0][1] = make_pair(0, 0);
	pts[1][0] = make_pair(N, N);
	pts[1][1] = make_pair(N, N);
	x_sort.insert(0);
	y_sort.insert(0);
	x_sort.insert(1);
	y_sort.insert(1);
	for (int i = 2; i < N+2; i++){
		cin >> pts[i][0].f >> pts[i][0].s >> pts[i][1].f >> pts[i][1].s;
		x_sort.insert(i);
		y_sort.insert(i);
	}
	for (int i = 2; i < N+2; i++){
		pii end = pts[i][1];
		int con1 = x_sort.upper_bound(end);
		int con2 = y_sort.upper_bound(end);


	}
}