/*
E. Bombs
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a permutation, p1,p2,…,pn.

Imagine that some positions of the permutation contain bombs, such that there exists at least one position without a bomb.

For some fixed configuration of bombs, consider the following process. Initially, there is an empty set, A.

For each i from 1 to n:

Add pi to A.
If the i-th position contains a bomb, remove the largest element in A.
After the process is completed, A will be non-empty. The cost of the configuration of bombs equals the largest element in A.

You are given another permutation, q1,q2,…,qn.

For each 1≤i≤n, find the cost of a configuration of bombs such that there exists a bomb in positions q1,q2,…,qi−1.

For example, for i=1, you need to find the cost of a configuration without bombs, and for i=n, you need to find the cost of a configuration with bombs in positions q1,q2,…,qn−1.

Input
The first line contains a single integer, n (2≤n≤300000).

The second line contains n distinct integers p1,p2,…,pn (1≤pi≤n).

The third line contains n distinct integers q1,q2,…,qn (1≤qi≤n).

Output
Print n space-separated integers, such that the i-th of them equals the cost of a configuration of bombs in positions q1,q2,…,qi−1.
*/

#include <bits/stdc++.h>
using namespace std;
const int MXN = 3e5+10;
int bitBombs[MXN], bitVal[MXN], n, loc[MXN], bombs[MXN];
void upd(int bit[], int ind){
	while (ind <= n){
		bit[ind] +=1;
		ind+=(ind&-ind);
	}
}
int qry(int bit[], int ind){
	int ans = 0;
	while (ind > 0){
		ans+=bit[ind]; ind-=(ind&-ind);
	}
	return ans;
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		int val;
		cin >> val;
		loc[val] = i;
	}
	for (int i = 1; i <=n; i++){
		cin >> bombs[i];
	}
	int ans = n;
	cout<< ans << ' ';
	set<int> vLocs;
	for (int i = 1; i<n; i++){
		int bomb = bombs[i]; upd(bitBombs, bomb);
		while (true){
			int curLoc = loc[ans];

			int numRight = qry(bitVal, n) - qry(bitVal, curLoc);
			int bombRight = qry(bitBombs, n) - qry(bitBombs, curLoc-1);
			auto it = vLocs.lower_bound(curLoc);
			if (it != vLocs.begin()){
				int leftLoc = *--it;
				if (qry(bitBombs, n) - qry(bitBombs, leftLoc-1)<numRight+2) break;
			}
			//cout << ans << ' ' << i << ' ' << numRight << ' ' << bombRight<< endl;
			if (bombRight >= numRight + 1){
				ans--;
				upd(bitVal, curLoc);
				vLocs.insert(curLoc);
			}
			else {
				break;
			}

		}
		
		cout << ans << ' ';
	}

}