/*
  D. Fafa and Ancient Alphabet
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ancient Egyptians are known to have used a large set of symbols  to write on the walls of the temples. Fafa and Fifa went to one of the temples and found two non-empty words S 1 and S 2 of equal lengths on the wall of temple written one below the other. Since this temple is very ancient, some symbols from the words were erased. The symbols in the set  have equal probability for being in the position of any erased symbol.

Fifa challenged Fafa to calculate the probability that S 1 is lexicographically greater than S 2. Can you help Fafa with this task?

You know that , i. e. there were m distinct characters in Egyptians' alphabet, in this problem these characters are denoted by integers from 1 to m in alphabet order. A word x is lexicographically greater than a word y of the same length, if the words are same up to some position, and then the word x has a larger character, than the word y.

We can prove that the probability equals to some fraction , where P and Q are coprime integers, and . Print as the answer the value , i. e. such a non-negative integer less than 109 + 7, such that , where  means that a and b give the same remainders when divided by m.

Input
The first line contains two integers n and m (1 ≤ n,  m ≤ 105) — the length of each of the two words and the size of the alphabet , respectively.

The second line contains n integers a 1, a 2, ..., a n (0 ≤ a i ≤ m) — the symbols of S 1. If a i = 0, then the symbol at position i was erased.

The third line contains n integers representing S 2 with the same format as S 1.

Output
Print the value , where P and Q are coprime and  is the answer to the problem.
  */


#include <iostream>

using namespace std;
const int MAX_N=1e5;
int n, m, s1[MAX_N], s2[MAX_N];
int pq, pq1;
const int MOD = 1e9+7;

#define ll long long

int mod_inv(int x, int num){
  if (num == 1) return x;
  int newx = mod_inv(x, num>>1);
  int n = (ll)newx*newx%MOD;
 // cout << n << ' ' << num << endl;
  return ((ll)n*((num&1)? x : 1)) % MOD;
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> s1[i];
  }
  for(int i = 0; i < n; i++){
    cin >> s2[i];
  }
  pq = 0;
  pq1 = 1;
  int inv = mod_inv(m, MOD-2);
  int inv2 = mod_inv(2*m, MOD-2);
  //cout << inv << inv2;
  for(int i = 0; i < n; i++){
    if (s1[i] != 0 && s2[i]!=0){
      if (s1[i] < s2[i]) break;
      if (s1[i] == s2[i]) continue;
      if (s1[i] > s2[i]) {
        pq= ((ll)pq + pq1) % MOD;
        break;
      }
    }
    if (s1[i] == 0 && s2[i] == 0){
      pq = ((ll)pq + (ll)pq1*(m-1)%MOD*inv2%MOD)%MOD;
      pq1 = (ll)pq1*inv%MOD;
    }
    if (s1[i] == 0 && s2[i]!=0){
      pq = ((ll)pq + (ll)pq1*(m-s2[i])%MOD*inv%MOD)%MOD;
      pq1 = (ll)pq1*inv%MOD;
    }
    if (s1[i]!=0 && s2[i]==0){
      pq = ((ll)pq + (ll)pq1*(s1[i]-1)%MOD*inv%MOD)%MOD;
      pq1 = (ll)pq1*inv%MOD;
    }
   // cout << pq  << endl;
  }
  cout << pq;
}
