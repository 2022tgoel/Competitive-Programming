#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>
using namespace std;
const int MXN = 2e5+10;
int n;
pair<pii, int> projects[MXN];
set<int> days;
map<int, int> comp;
int pref[2*MXN];
int overlap[MXN];
long long dp[MXN];
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> projects[i].f.s >> projects[i].f.f >> projects[i].s;
		days.insert(projects[i].f.s); days.insert(projects[i].f.f);
	}
	int x =0 ;
	for (int day : days) comp[day] = ++x;
	//x is last ending day
	assert(x < 2*MXN);
	for (int i = 0; i < n; i++){
		projects[i].f.f = comp[projects[i].f.f];
		projects[i].f.s = comp[projects[i].f.s];
	}
	sort(projects, projects+n);
	int oldend = 0;
	for (int i = 0; i < n; i++){
		int end = projects[i].f.f; assert(end < 2*MXN);
		for (int j = oldend+1; j <=end;j++) pref[j] = pref[j-1];
		pref[end]+=1;
		overlap[i] = pref[projects[i].f.f] - pref[projects[i].f.s-1];
		oldend = end;
	}
	dp[0] = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++){
		long long score = projects[i].s + dp[i + 1 - overlap[i]];
		dp[i+1] = max(dp[i], score);
		ans = max(ans, dp[i+1]);
	}
	cout << ans;
}