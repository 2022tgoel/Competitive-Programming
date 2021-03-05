
/*
 *Tired of his stubborn cowlick, Farmer John decides to get a haircut. He has N (1≤N≤105) strands of hair arranged in a line, and strand i is initially Ai micrometers long (0≤Ai≤N). Ideally, he wants his hair to be monotonically increasing in length, so he defines the "badness" of his hair as the number of inversions: pairs (i,j) such that i<j and Ai>Aj.
For each of j=0,1,…,N−1, FJ would like to know the badness of his hair if all strands with length greater than j are decreased to length exactly j.

(Fun fact: the average human head does indeed have about 105 hairs!)

INPUT FORMAT (file haircut.in):
The first line contains N.
The second line contains A1,A2,…,AN.

OUTPUT FORMAT (file haircut.out):
For each of j=0,1,…,N−1, output the badness of FJ's hair on a new line.
Note that the large size of integers involved in this problem may require the use of 64-bit integer data types (e.g., a "long long" in C/C++).

SAMPLE INPUT:
5
5 2 3 3 0
SAMPLE OUTPUT:
0
4
4
5
7 
 */
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int N, a[MAXN], bit[MAXN];
long long inv[MAXN];
deque<int> ind[MAXN];
void upd(int ind){
	while (ind <= N){
		bit[ind]+=1;
		ind+=(ind&-ind);
	}
}
int qry(int ind){
	int ans = 0;
	while (ind > 0){
		ans +=bit[ind];
		ind-=(ind&-ind);
	}
	return ans;
}

int main(){
	ifstream cin ("haircut.in");
	ofstream cout ("haircut.out");
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		ind[a[i]].push_front(i);
	}
	for (int i = N; i>=0; i--){
		for (int x : ind[i]){
			int idx = x + 1;
			inv[i] += qry(idx);
			upd(idx);
		}
		//cout << i << ' ' << inv[i] << qry(10) << endl;
	}
	long long ans = 0;
	for (int i = 0; i < N; i++){
		cout << ans << endl; 
		ans += inv[i];
	}
}

