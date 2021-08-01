/*F. Network Coverage
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The government of Berland decided to improve network coverage in his country. Berland has a unique structure: the capital in the center and n cities in a circle around the capital. The capital already has a good network coverage (so the government ignores it), but the i-th city contains ai households that require a connection.

The government designed a plan to build n network stations between all pairs of neighboring cities which will maintain connections only for these cities. In other words, the i-th network station will provide service only for the i-th and the (i+1)-th city (the n-th station is connected to the n-th and the 1-st city).

All network stations have capacities: the i-th station can provide the connection to at most bi households.

Now the government asks you to check can the designed stations meet the needs of all cities or not — that is, is it possible to assign each household a network station so that each network station i provides the connection to at most bi households.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains the single integer n (2≤n≤106) — the number of cities and stations.

The second line of each test case contains n integers (1≤ai≤109) — the number of households in the i-th city.

The third line of each test case contains n integers (1≤bi≤109) — the capacities of the designed stations.

It's guaranteed that the sum of n over test cases doesn't exceed 106.

Output
For each test case, print YES, if the designed stations can meet the needs of all cities, or NO otherwise (case insensitive).
*/
#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	cin >> t;
	for (int j= 0; j < t; j++){
		int n;
		cin >> n;
		vector<int> connect(n);
		vector<int> net(n);
		for (int i = 0; i < n; i++){
			cin >> connect[i];
		}
		for (int i =0; i < n; i++){
			cin >> net[i];
		}
		int fail = false;
		for (int i = 0; i < n; i++){
			if (net[i] + net[(i-1+n)%n] < connect[i]){
				cout << "NO" << endl;
				fail = true;
				break;
			}
		}
		if (fail) continue;
		//
		int firstRight = min(connect[0], net[0]);
		int firstLeft = connect[0] - firstRight;
		//
		int swp = min(firstRight, net[n-1] - firstLeft);
		int lc = firstRight;
		//greedy - remaining households
		for (int i = 1; i< n;i++){
			int placedRight = connect[i] - min(net[i-1]-lc, connect[i]);
			if (placedRight > net[i]){
				//need to make swaps
				int numSwp = placedRight - net[i];
				if (numSwp > swp) {
					fail = true; break;
				}
				swp-=numSwp;
				firstLeft+=numSwp;
				placedRight=net[i];
			}
			if (i == n-1 && placedRight > net[i] - firstLeft){
				fail = true; break;
			}
			lc = placedRight;
			swp = min(swp, placedRight);
		}
		if (fail) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
		}
	}
}