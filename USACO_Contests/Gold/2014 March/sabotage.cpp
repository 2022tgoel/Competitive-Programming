/*
Problem 2: Sabotage [Brian Dean, 2014]

Farmer John's arch-nemesis, Farmer Paul, has decided to sabotage Farmer
John's milking equipment!

The milking equipment consists of a row of N (3 <= N <= 100,000)
milking machines, where the ith machine produces M_i units of milk (1
<= M_i <= 10,000).  Farmer Paul plans to disconnect a contiguous block
of these machines -- from the ith machine up to the jth machine (2 <=
i <= j <= N-1); note that Farmer Paul does not want to disconnect
either the first or the last machine, since this will make his plot
too easy to discover.  Farmer Paul's goal is to minimize the average
milk production of the remaining machines.  Farmer Paul plans to
remove at least 1 cow, even if it would be better for him to avoid
sabotage entirely.

Fortunately, Farmer John has learned of Farmer Paul's evil plot, and
he is wondering how bad his milk production will suffer if the plot
succeeds.  Please help Farmer John figure out the minimum average milk
production of the remaining machines if Farmer Paul does succeed.

PROBLEM NAME: sabotage

INPUT FORMAT:

* Line 1: The integer N.

* Lines 2..1+N: Line i+1 contains M_i.

SAMPLE INPUT (file sabotage.in):

5
5
1
7
8
2

OUTPUT FORMAT:

* Line 1: The lowest possible average Farmer Paul can achieve, rounded
        to 3 digits after the decimal point, and printed with 3 digits
        after the decimal point.

SAMPLE OUTPUT (file sabotage.out):

2.667

OUTPUT DETAILS:

The optimal solution is to remove the 7 and 8, leaving 5, 1, and 2, whose
average is 8/3.
*/
#include <bits/stdc++.h>
#define long long long
using namespace std;
const int MXN = 1e5;
int N;
long arr[MXN];

bool check(long x){
	long sum = 0;
	long minp= 1000000000; //minimum prefix sum - must include first
	long maxr = -1000000000;
	for (int i = 0; i <N; i++){
		sum +=(arr[i]-x);
		if (i > 0 && i <N-1){
			//best range
			maxr = max(sum - minp, maxr);
		}
		minp = min(minp, sum);
	}
	return (sum-maxr)<=0;
	//1 to n-2
}

long binary_search(){
	long lo = 1000; long hi = 1000000000;
	while (hi > lo){
		long mid = (hi + lo) / 2;
//		cout << lo <<' ' << mid << ' ' << hi << endl;
		if (check(mid)){
			hi=mid;
		}
		else{
			lo = mid+1;
		}

	}
	return lo;
}

int main(){
	freopen ("sabotage.in", "r", stdin);
	freopen ("sabotage.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i]*=100000;
	}
	printf("%.3lf\n", (binary_search()/100000.0));
}