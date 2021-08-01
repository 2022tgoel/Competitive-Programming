/*
If the girl doesn't go to Denis, then Denis will go to the girl. Using this rule, the young man left home, bought flowers and went to Nastya.

On the way from Denis's house to the girl's house is a road of n lines. This road can't be always crossed in one green light. Foreseeing this, the good mayor decided to place safety islands in some parts of the road. Each safety island is located after a line, as well as at the beginning and at the end of the road. Pedestrians can relax on them, gain strength and wait for a green light.

Denis came to the edge of the road exactly at the moment when the green light turned on. The boy knows that the traffic light first lights up g seconds green, and then r seconds red, then again g seconds green and so on.

Formally, the road can be represented as a segment [0,n]. Initially, Denis is at point 0. His task is to get to point n in the shortest possible time.

He knows many different integers d1,d2,…,dm, where 0≤di≤n  — are the coordinates of points, in which the safety islands are located. Only at one of these points, the boy can be at a time when the red light is on.

Unfortunately, Denis isn't always able to control himself because of the excitement, so some restrictions are imposed:

He must always move while the green light is on because it's difficult to stand when so beautiful girl is waiting for you. Denis can change his position by ±1 in 1 second. While doing so, he must always stay inside the segment [0,n].
He can change his direction only on the safety islands (because it is safe). This means that if in the previous second the boy changed his position by +1 and he walked on a safety island, then he can change his position by ±1. Otherwise, he can change his position only by +1. Similarly, if in the previous second he changed his position by −1, on a safety island he can change position by ±1, and at any other point by −1.
At the moment when the red light is on, the boy must be on one of the safety islands. He can continue moving in any direction when the green light is on.
Denis has crossed the road as soon as his coordinate becomes equal to n.

This task was not so simple, because it's possible that it is impossible to cross the road. Since Denis has all thoughts about his love, he couldn't solve this problem and asked us to help him. Find the minimal possible time for which he can cross the road according to these rules, or find that it is impossible to do.

Input
The first line contains two integers n and m (1≤n≤106,2≤m≤min(n+1,104))  — road width and the number of safety islands.

The second line contains m distinct integers d1,d2,…,dm (0≤di≤n)  — the points where the safety islands are located. It is guaranteed that there are 0 and n among them.

The third line contains two integers g,r (1≤g,r≤1000)  — the time that the green light stays on and the time that the red light stays on.

Output
Output a single integer  — the minimum time for which Denis can cross the road with obeying all the rules.

If it is impossible to cross the road output −1.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MXM = 1e4+10;
const int MXG = 1e3+10;
const int MX = 1e8; //assuming answer is smaller than this
int n, m, g, r, pts[MXM], dp[MXM][MXG]; // assumed points are sorted

int calc (int node, int green){
	if (dp[node][green] !=0 || (node == 0 && green == 0)) return dp[node][green];
	dp[node][green] = MX;
	if (node > 0) {
		int dist = (pts[node] - pts[node-1]);
		int gnew = (green > 0 ? green : g) - dist;
		if (gnew >= 0) {
			int t = calc(node-1, gnew);
			if (t < MX) dp[node][green] = min(dp[node][green], t+ dist + ((green == 0 && node < m-1) ? r : 0));
		}
	}
	if (node < m-1){
		int dist = (pts[node+1] - pts[node]);
		int gnew = (green > 0 ? green : g) - dist;
		if (gnew >= 0) {
			int t = calc(node+1, gnew);
			if (t < MX) dp[node][green] = min(dp[node][green], t+ dist + ((green == 0 && node < m-1) ? r : 0));
		}
	}
	return dp[node][green];
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> pts[i];
	}
	cin >> g >> r;
	dp[0][0] = 0; //how much green time consumed
	int ans = MX;
	for (int i = 0; i < g; i++)
		ans = min(ans, calc(m-1, i));
	cout << ((ans == MX) ? -1 : ans);
}