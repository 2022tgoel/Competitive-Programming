/*
WITH SQRT DECOMPOSITION

Given an array of n integers, your task is to process q queries of the form: what is the sum of values in range [a,b]?

Input

The first input line has two integers n and q: the number of values and queries.

The second line has n integers x1,x2,…,xn: the array values.

Finally, there are q lines describing the queries. Each line has two integers a and b: what is the sum of values in range [a,b]?

Output

Print the result of each query.

Constraints
1≤n,q≤2⋅105
1≤xi≤109
1≤a≤b≤n
Example

Input:
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3

Output:
11
2
24
4
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MXN  =2e5;
int N, Q, K;
int arr[MXN];
ll blocks[MXN];

ll qry(int a, int b){
	ll ans = 0;
	int cur = a;
	while (cur <=b){
		if (cur%K == 0 && b >= cur+K-1){
			ans+=blocks[cur/K]; cur+=K;
		}
		else{
			ans+=arr[cur]; cur+=1;
		}
	}
	return ans;
	
}

int main(){
	cin >> N >> Q;
	K= sqrt(N);
	for (int i= 0; i < N;i++){
		cin >> arr[i];
		blocks[i/K]+=arr[i];
	}
	for (int i = 0; i < Q; i++){
		int a,b; cin >> a >> b; a--; b--;
		cout << qry(a, b) << endl;
	}
}