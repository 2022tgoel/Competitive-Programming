#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;
map<int, pair<pii, pii>> cows;
int N, M;
int main(){
	ifstream cin("taxi.in");
	ofstream cout("taxi.out");
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		int a, b; cin >> a >> b;
		if (a==b) continue; // nothing needs to be done here
		if (a < b){
			cows[a].f.f+=1;
			cows[b].f.s+=1;
		}
		else {
			cows[a].s.s+=1;
			cows[b].s.f+=1;
		}
	}
	int fr = 0; // forward
	int bck = 0; //back
	long long ans = 0;
	for (auto it = cows.begin(); it!=--cows.end(); it++){
		long long loc = it->f;
		it++; long long nextLoc = it->f; it--;
		fr+=cows[loc].f.f; fr-=cows[loc].f.s;
		bck+=cows[loc].s.f; bck-=cows[loc].s.s;
		//cout << loc << ' ' << nextLoc << ' ' << fr << ' ' << bck << endl;
		if (fr > bck){
			ans += (nextLoc - loc)*(2*fr-1);
		}
		else ans+=(nextLoc - loc)*(2*bck+1);
	}
	cout << (ans + cows.begin()->f + (M - (--cows.end())->f) )  << endl;
}
