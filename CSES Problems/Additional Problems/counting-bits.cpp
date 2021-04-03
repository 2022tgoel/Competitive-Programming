/*
 * Your task is to count the number of one bits in the binary representations of integers between 1 and n.

Input

The only input line has an integer n.

Output

Print the number of one bits in the binary representations of integers between 1 and n.

Constraints
1≤n≤1015
Example

Input:
7

Output:
12

Explanation: The binary representations of 1…7 are 1, 10, 11, 100, 101, 110, and 111, so there are a total of 12 one bits.
  */

#include <iostream>
#include <math.h>
using namespace std;
#define ll long long
ll left_bit(ll n){
  ll a = 0;
  while (n>0){
    n>>=1;
    a++;
  }
  return a-1;
}

ll count (ll n){
  ll ans = 0;
  while (n>0){
    int len = left_bit(n);
    ans += (len)*((ll)1 << len-1);
    n ^= ((ll)1 << len);
    ans += n+1;
   // cout << len << n << endl;
  }
  return ans;
}


int main(){
  ll N;
  cin >> N;
  cout << count(N);
}
