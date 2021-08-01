/*
Your task is to calculate n binomial coefficients modulo 109+7.

A binomial coefficient (ab) can be calculated using the formula a!b!(a−b)!. We assume that a and b are integers and 0≤b≤a.

Input

The first input line contains an integer n: the number of calculations.

After this, there are n lines, each of which contains two integers a and b.

Output

Print each binomial coefficient modulo 109+7.

Constraints
1≤n≤105
0≤b≤a≤106
Example

Input:
3
5 3
8 1
9 5

Output:
10
8
126
*/

#include <iostream>
using namespace std;
#define ll long long
#define MAX_B 1000000
#define MOD 1000000007
int factor[MAX_B];
int power(int a, int b){
  if (b==0) return 1;
  int ans = power(a, b>>1);
  ans = (long long)ans*ans%MOD;
  if (b&1) ans = (long long)ans*a%MOD;
  return ans;
}

int mod_inverse(int a, int b){
  return power((ll)factor[b]*factor[a-b]%MOD, MOD-2);
}

int main(){
  int N;
  cin >>N;
  factor[0] = 1;
  factor[1] = 1;
  for(int i = 2; i <=MAX_B; i++) factor[i] = (ll)factor[i-1]*i%MOD;
  for(int i = 0; i < N; i++){
    int a, b;
    cin >> a >> b;
    //    cout << factor[a]<< endl;
    if (b==0) cout << 1 << endl;
    else if (b==1) cout << a << endl;
    else cout << ((ll)factor[a]*mod_inverse(a, b)%MOD) << endl;
  }
}
