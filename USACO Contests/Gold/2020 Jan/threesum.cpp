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
*/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define s second
#define f first
using namespace std;
const int MXN = 5e4+1;
int N, Q;
long bit[MXN];
int A[MXN];
const int MXQ = 1e5;
pair<pii, int> q[MXQ];
unordered_map<int, vector<int>> mp;
long ans[MXQ];
void upd(int ind){
	while (ind<=N){
		bit[ind]+=1;
		ind+=(ind&-ind);
	}
}
long qry(int ind){
	long ans = 0;
	while (ind>0){
		ans+=bit[ind];
		ind-=(ind&-ind);
	}
	return ans;
}
int main(){
	ifstream cin("threesum.in");
	ofstream cout("threesum.out");
	cin >> N >> Q; 
	for (int i = 1; i <=N; i++) {
		cin >> A[i];
		mp[A[i]].push_back(i);
	}
	for (int i = 0; i < Q; i++){
		cin >> q[i].f.s >> q[i].f.f; q[i].s = i;
	}
	sort(q, q+Q);
	int lend = 0;
	for (int i = 0; i < Q; i++){
		int end = q[i].f.f;
		for (int z= lend+1; z <=end; z++){
			for (int y = 1; y < z; y++){
				int opp = -1*A[y] + -1*A[z];
				for (int x : mp[opp]){
					if (x>=y) break;
					upd(x);
					//cout << z << ' ' << x << endl;
				}
			}
		}
		lend = end;
		//cout << end << ' ' << qry(end) << ' ' << q[i].f.s-1 << ' ' << qry(q[i].f.s-1) << endl;
		//assert((qry(end) - qry(q[i].f.s-1))%2 == 0);
		ans[q[i].s] = (qry(end) - qry(q[i].f.s-1));
	}
	for (int i = 0; i < Q; i++){
		cout << ans[i] << endl;
	}
}