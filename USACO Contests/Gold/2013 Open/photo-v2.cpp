#include <bits/stdc++.h>

using namespace std;
const int MXN = 2e5+1;
int N, M;
vector<int> starts[MXN];
int fir[MXN]; //last location that any other spotted cow can be if a spotted cow is here
int dp[MXN];
int max_range(int i, int j){
	int ans = -1;
	for (int k = i; k <=j; k++){
		ans = max(ans, dp[k]);
	}
	return ans;
}

int main(){
	ifstream cin("photo.in");
	ofstream cout("photo.out");
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int a, b; cin >> a >> b;
		starts[b].push_back(a);
	}
	fir[N+1] = N;
	for (int i = N; i >=1; i--){
		fir[i] = min(i-1, fir[i+1]);
		for (int start : starts[i]){
			fir[i] = min(fir[i], start -1);
		}
	}
	for (int i =1; i <=N; i++){
		dp[i] = -1;
	}
	dp[1] = 1;
	int rangeStart = 0; // spotty must be after, otherwise there would be an uncovered range
	for (int i = 1; i<=N; i++){
		for (int start : starts[i]){
			rangeStart = max(rangeStart, start);
		}
		int x = max_range(rangeStart, fir[i+1]);
		if (x!=-1) dp[i+1] = x+1;//maximum of the range [rangeStart, fir[i+1]]
	}
	cout << max_range(rangeStart, N) << endl;
}