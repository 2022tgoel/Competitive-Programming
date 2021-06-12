#include <bits/stdc++.h>

using namespace std;
const int MXN = 2e3+1;
int N, M;
vector<int> starts[MXN];
int fir[MXN]; //last location that any other spotted cow can be if a spotted cow is here
int dp[MXN][MXN];
int main(){
	ifstream cin("photo.in");
	ofstream cout("photo.out");
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int a, b; cin >> a >> b;
		starts[b].push_back(a);
	}
	set<int> s;
	for (int i = N; i >=1; i--){
		s.insert(i);
		for (int start : starts[i]){
			s.insert(start);
		}
		fir[i] = *(s.begin())-1;
	}
	for (int i = 1; i <=N; i++){
		for (int j = 0; j<=i; j++){
			dp[i][j] = -1; // start with everything being impossible
		}
	}
	int l = 0;
	// [covers ranges till here][no spotty after this point]
	for (int i = 1; i <=N; i++){
		for (int start : starts[i]){
			l = max(start, l);
		}
		for (int j = l; j<=i; j++){
			if (j==0) {
				dp[i][j] = 0; 
				continue;
			}
			else dp[i][j] = dp[i][j-1];
			if (dp[j-1][fir[j]]!=-1) dp[i][j] = max(dp[j-1][fir[j]]+1, dp[i][j]); //placing the spotted cow at j
		}
	}
	int ans = -1;
	for (int i = 0; i <=N; i++){
		ans = max(ans, dp[N][i]);
	}
	cout << ans << endl;
}