/*
Bessie is conducting a business trip in Bovinia, where there are N (2≤N≤1000) cities labeled 1…N connected by M (1≤M≤2000) one-way roads. Every time Bessie visits city i, Bessie earns mi moonies (0≤mi≤1000). Starting at city 1 Bessie wants to visit cities to make as much mooney as she can, ending back at city 1. To avoid confusion, m1=0.
Mooving between two cities via a road takes one day. Preparing for the trip is expensive; it costs C⋅T2 moonies to travel for T days (1≤C≤1000).

What is the maximum amount of moonies Bessie can make in one trip? Note that it may be optimal for Bessie to visit no cities aside from city 1, in which case the answer would be zero.

INPUT FORMAT (file time.in):
The first line contains three integers N, M, and C.
The second line contains the N integers m1,m2,…mN.

The next M lines each contain two space-separated integers a and b (a≠b) denoting a one-way road from city a to city b.

OUTPUT FORMAT (file time.out):
A single line with the answer.
SAMPLE INPUT:
3 3 1
0 10 20
1 2
2 3
3 1
SAMPLE OUTPUT:
24
The optimal trip is 1→2→3→1→2→3→1. Bessie makes 10+20+10+20−1⋅62=24 moonies in total.

Problem credits: Richard Peng and Mark Gordon
*/
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
const int MXN = 1e3+10;
const int MXM = 2e3+10;
int N, M, C, m[MXN];
int dp[MXN][1000]; //node and time
pii edges[MXM];
int main(){
	ifstream cin ("time.in");
	ofstream cout ("time.out");
	cin >> N >> M >> C;
	for (int i = 0; i < N;i++){
		cin  >> m[i];
	}
	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[i] = make_pair(a, b);
	}
	for (int t = 0; t < 1000; t++){
		for (int n = 0; n < N; n++){
			dp[n][t] = -1; //initially, can't get to any node
		}
	}
	dp[0][0] = 0;
	for (int t = 1; t<1000; t++){
		for (int e = 0; e < M; e++){
			int x = dp[edges[e].f][t-1]; //moonies you get going to the first one
			if (x==-1) continue;
			else dp[edges[e].s][t] = max(dp[edges[e].s][t], x + m[edges[e].s]);
		}
	}
	int ans = 0;
	for (int t = 0; t < 1000;t++){
		if (dp[0][t] == -1) continue;
		ans = max(ans, dp[0][t] - C*t*t);
	}
	cout << ans;
}