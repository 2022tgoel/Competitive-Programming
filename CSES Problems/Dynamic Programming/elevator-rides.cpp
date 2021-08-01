/*
There are n people who want to get to the top of a building which has only one elevator. You know the weight of each person and the maximum allowed weight in the elevator. What is the minimum number of elevator rides?

Input

The first input line has two integers n and x: the number of people and the maximum allowed weight in the elevator.

The second line has n integers w1,w2,…,wn: the weight of each person.

Output

Print one integer: the minimum number of rides.

Constraints
1≤n≤20
1≤x≤109
1≤wi≤x
Example

Input:
4 10
4 8 6 1

Output:
2
*/

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int> 
#define s second
#define f first
const int MXN = 21;
const int MXM = 2e6;
pii dp[MXM];
int a[MXN];
int main(){
	int n, w;
	cin >> n >> w;
	for (int i = 0; i < n; i++) cin >> a[i];
	dp[0] = make_pair(0, 0); //0 trips and 0 used space
	for (int mask = 1; mask < (1<<n); mask++){
		dp[mask] = make_pair(MXN, w);
		for (int j = 0; j < n; j++){
			if (mask&(1<<j)){
				int x = mask^(1<<j);
				if (dp[x].s + a[j] > w) dp[mask] = min(dp[mask], make_pair(dp[x].f+1, a[j]));
				else dp[mask] = min(dp[mask], make_pair(dp[x].f, dp[x].s+a[j]));
			}
		}
	}
	cout << dp[(1<<n)-1].f+ (dp[(1<<n)-1].s ? 1 : 0);
}