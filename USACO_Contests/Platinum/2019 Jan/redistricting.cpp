#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;
const int MXN =3e5+10;
int N, K;
set<pair<pii, int>> window;
int dp[MXN];
int pref[MXN];

int main(){
	ifstream cin("redistricting.in");
	ofstream cout("redistricting.out");
	cin >> N >> K;
	for (int i = 1; i <= N; i++){
		char c; cin >> c;
		if (c == 'H'){
			pref[i] = pref[i-1]+1;
		}
		else pref[i] = pref[i-1]-1;
	}
	dp[0] = 0;
	window.insert({{dp[0], pref[0]}, 0});
	for (int i = 1; i <=N; i++){
		//extract min
		pair<pii, int> m = *window.begin();
		dp[i] = m.f.f + (pref[i] - m.f.s <=0);
		//update window
		if (i-K>=0) window.erase({{dp[i-K], pref[i-K]}, i-K});
		window.insert({{dp[i], pref[i]}, i});
	}
	cout << dp[N];
}