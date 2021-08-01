/*
Let σ(n) denote the sum of divisors of an integer n. For example, σ(12)=1+2+3+4+6+12=28.

Your task is to calculate the sum ∑ni=1σ(i) modulo 109+7.

Input

The only input line has an integer n.

Output

Print ∑ni=1σ(i) modulo 109+7.

Constraints
1≤n≤1012
Example

Input:
5

Output:
21
*/
#include <iostream>
#include <cstring>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int sum_range(ll u, ll i){
  u%=MOD;
  i%=MOD;
  ll sum  = (u*(u+1)/2 - i*(i-1)/2 + (ll)MOD*MOD)%MOD;
  return sum;
}

int main(){
  ll N;
  cin >> N;
  ll ans = 0;
  for(ll i=1; i<=N; i++){
    ll u = N/(N/i); //upper bound of values that appear N/i times 
    ans+= (N/i%MOD)*(sum_range(u, i))%MOD;
    ans%=MOD;
    i = u;
    //    cout << ans << ' ' << i << endl;
  }
  cout << ans;
}
