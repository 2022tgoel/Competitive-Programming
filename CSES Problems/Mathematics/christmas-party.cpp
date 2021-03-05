/*
There are n children at a Christmas party, and each of them has brought a gift. The idea is that everybody will get a gift brought by someone else.

In how many ways can the gifts be distributed?

Input

The only input line has an integer n: the number of children.

Output

Print the number of ways modulo 109+7.

Constraints
1≤n≤106
Example

Input:
4

Output:
9
*/
#include <iostream>
#define ll long long
using namespace std;
const int MAX_N = 1e6+1, MOD=1e9+7;
int main(){
  int N;
  cin >> N;
  int ans[MAX_N];
  ans[0] = 1;
  ans[1] = 0;
  for(int i = 2; i <=N; i++){
    ans[i] = ((ll)(i-1) *(ans[i-1] + ans[i-2]))%MOD;
  }
  cout << ans[N];
}
