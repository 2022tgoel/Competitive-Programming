/*
Given a string, your task is to calculate the number of different strings that can be created using its characters.

Input

The only input line has a string of length n. Each character is between a–z.

Output

Print the number of different strings modulo 109+7.

Constraints
1≤n≤106
Example

Input:
aabac

Output:
20
*/

#include <iostream>
#include <map>
using namespace std;
#define ll long long
#define MOD 1000000007
int factor[1000001];
int power(int a, int b){
  if (b==0) return 1;
  int ans = power(a, b>>1);
  ans = (long long)ans*ans%MOD;
  if (b&1) ans = (long long)ans*a%MOD;
  return ans;
}

int mod_inverse(int c){
  return power(c, MOD-2);
}

int main(){
  string inp;
  cin >>inp;
  factor[0] = 1;

  for(int i = 1; i <=inp.size(); i++) factor[i] = (ll)factor[i-1]*i%MOD;
  int ans = factor[inp.size()];
  map<char, int> count;
  for(char c : inp) count[c]++;
  for(pair<char, int> c : count){
    //    cout << c.first <<  ' ' << c.second << x' ';
    ans = ((ll)ans*mod_inverse(factor[c.second])%MOD);
  }
  cout << ans << endl;
 }

  
