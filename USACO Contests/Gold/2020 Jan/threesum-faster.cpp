/*
Farmer John believes he has made a major breakthrough in algorithm design: he claims to have found a nearly linear time algorithm for the 3SUM problem, an algorithmic problem famous for the fact that no known solution exists running in substantially better than quadratic time. One formulation of the 3SUM problem is the following: given an array s1,…,sm of integers, count the number of unordered triples of distinct indices i,j,k such that si+sj+sk=0.
To test Farmer John's claim, Bessie has provided an array A of N integers (1≤N≤5000). Bessie also asks Q queries (1≤Q≤105), each of which consists of two indices 1≤ai≤bi≤N. For each query, Farmer John must solve the 3SUM problem on the subarray A[ai…bi].

Unfortunately, Farmer John has just discovered a flaw in his algorithm. He is confident that he can fix the algorithm, but in the meantime, he asks that you help him pass Bessie's test!

SCORING:
Test cases 2-4 satisfy N≤500.
Test cases 5-7 satisfy N≤2000.
Test cases 8-15 satisfy no additional constraints.
INPUT FORMAT (file threesum.in):
The first line contains two space-separated integers N and Q. The second line contains the space-separated elements A1,…,AN of array A. Each of the subsequent Q lines contains two space-separated integers ai and bi, representing a query.
It is guaranteed that −106≤Ai≤106 for every array element Ai.

OUTPUT FORMAT (file threesum.out):
The output should consist of Q lines, with each line i containing a single integer---the answer to the i-th query. Note that you should use 64-bit integers to avoid overflow.
SAMPLE INPUT:
7 3
2 0 -1 1 -2 3 3
1 5
2 4
1 7
SAMPLE OUTPUT:
2
1
4
For the first query, the possible triples are (A1,A2,A5) and (A2,A3,A4).

Problem credits: Dhruv Rohatgi
*/
#include <bits/stdc++.h>
using namespace std;
const int MXN = 5010;
const int MXA = 1e6;
int N, Q, a[MXN];
long ans[MXN][MXN];
int s[2*MXA+10];
int main(){
	ifstream cin ("threesum.in");
	ofstream cout ("threesum.out");
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++){
		for (int j = i+2; j < N; j++){
			s[a[j-1] + MXA]++;
			int sum = a[i]+a[j]; 
			if (sum > MXA || sum < -1*MXA) continue; // doesn't fit in array, it is impossible 
			ans[i][j] = s[-1*sum + MXA];
		}
		//clear the array
		for (int j = i+1; j < N; j++){
			s[a[j] + MXA] = 0;
		}
	}
	for (int k = 2; k < N; k++){
		for (int i = 0; i < N-k; i++){
			int j = i+k;
			ans[i][j] += ans[i+1][j] + ans[i][j-1] - ans[i+1][j-1];
		}
	}
	for (int i = 0; i < Q; i++){
		int a, b;
		cin >> a >> b;
		cout << ans[a-1][b-1] << endl;
	}
}