#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int MXN = 2e5+10;
int N;
pair<int, int> tvs[MXN];
set<int> locs;
map<int, int> cmp;
int pref[4*MXN];
int dx[4*MXN];
pair<int,int> pos;
int st[4*MXN][20];
int lg[4*MXN];
int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> tvs[i].f >> tvs[i].s;
		locs.insert(tvs[i].f); locs.insert(tvs[i].s);
	}
	int x=1;
	int last = *locs.begin()-1;
	for (int n : locs){
		if (n - last > 1) { //you should insert a gap
			x++;
		}
		cmp[n] =x++;
		last = n;
	}
	assert(x<=8e5); //1..2*N at most, 1..x-1
	for (int i = 0; i < N; i++){
		dx[cmp[tvs[i].f]]+=1;
		dx[cmp[tvs[i].s]+1]-=1;
	}
	for (int i =1; i < x;i++){
		lg[i] = (i==1 ? 0 : lg[i/2]+1);
		pref[i] = pref[i-1]+dx[i];
	}
	assert(pref[x-1] == -1*dx[x]); // adding should get to 0 at x
	//sparse table on the prefix array
	for (int i =1;i<x; i++){
		st[i][0] = pref[i];
	}
	for (int j=1; j<=19;j++){ //(1<<j) length 
		for (int i = 1; i +(1<<j) <= x; i++){
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}
	for (int i = 0; i < N;i++){
		int l = cmp[tvs[i].f]; int r = cmp[tvs[i].s];
		int j = lg[r-l+1]; //2 2^j windows
		if (min(st[l][j], st[r-(1<<j)+1][j]) > 1){ //more than 1 tv throughout entire interval
			cout << i+1 << endl; return 0;
		}
	}
	cout << -1 << endl;
}