#include <bits/stdc++.h>

using namespace std;
map<char, int> comp;
int adj[50][50];
int dp[20000000];
int main(){
  string inp ="";
  cin >> inp;
  int len = inp.length();
  int x = 0;
  /*
  for (int i = 0; i < len; i++){
    comp[inp[i]] = 0;
  }
  for (auto m : comp) comp[m.first]=x++;
  */
  for(int i = 0; i < len; i++) {
    if (comp.count(inp[i]) == 0) comp[inp[i]]=x++;
  }
  assert(x <=20);
  for (int i = 1; i < len; i++){
    adj[comp[inp[i-1]]][comp[inp[i]]] +=1;
  }
  int n = comp.size();
  assert(n<=20);
  assert((1<<n) < 2000000);
  dp[0] = 1;
  for (int i = 1; i < 1<<n; i++){
    dp[i] = len;
    for (int j = 0; j< n; j++){
      if ((i&(1<<j))!=0){
        int sum = dp[i^(1<<j)];
        for (int k = 0; k < n; k++){
          if((i&(1<<k))!=0) sum+= adj[j][k];
        } 
        dp[i] = min(dp[i], sum);
      }
    }
  }
  cout << dp[(1<<n)-1];
}

