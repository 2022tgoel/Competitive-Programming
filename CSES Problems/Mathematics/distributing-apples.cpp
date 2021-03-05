/*
There are n children and m apples that will be distributed to them. Your task is to count the number of ways this can be done.

For example, if n=3 and m=2, there are 6 ways: [0,0,2], [0,1,1], [0,2,0], [1,0,1], [1,1,0] and [2,0,0].

Input

The only input line has two integers n and m.

Output

Print the number of ways modulo 109+7.

Constraints
1≤n,m≤106
Example

Input:
3 2

Output:
6
*/
#include <iostream>
using namespace std;
#define ll long long
const int MAX = 2e6, MOD = 1e9+7;

int power(int a, int b){
  if (b==0) return 1;
  int ans = power(a, b>>1);
  ans = (long long)ans*ans%MOD;
  if (b&1) ans = (long long)ans*a%MOD;
  return ans;
}

int main(){
  int N, M, factor[MAX];
  cin >> N >> M;
  factor[0] = 1;
  for(int i = 1; i < N+M; i++) factor[i] = (ll)factor[i-1]*i%MOD;
  // cout << factor[N+M-1];
  cout << (ll)factor[N+M-1]*power((ll)factor[N-1]*factor[M]%MOD, MOD-2)%MOD;
}
