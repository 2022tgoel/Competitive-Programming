/*
 * Farmer John has installed a new system of N−1 pipes to transport milk between the N stalls in his barn (2≤N≤50,000), conveniently numbered 1…N. Each pipe connects a pair of stalls, and all stalls are connected to each-other via paths of pipes.
FJ is pumping milk between K pairs of stalls (1≤K≤100,000). For the ith such pair, you are told two stalls si and ti, endpoints of a path along which milk is being pumped at a unit rate. FJ is concerned that some stalls might end up overwhelmed with all the milk being pumped through them, since a stall can serve as a waypoint along many of the K paths along which milk is being pumped. Please help him determine the maximum amount of milk being pumped through any stall. If milk is being pumped along a path from si to ti, then it counts as being pumped through the endpoint stalls si and ti, as well as through every stall along the path between them.

INPUT FORMAT (file maxflow.in):
The first line of the input contains N and K.
The next N−1 lines each contain two integers x and y (x≠y) describing a pipe between stalls x and y.

The next K lines each contain two integers s and t describing the endpoint stalls of a path through which milk is being pumped.

OUTPUT FORMAT (file maxflow.out):
An integer specifying the maximum amount of milk pumped through any stall in the barn.
SAMPLE INPUT:
5 10
3 4
1 5
4 2
5 4
5 4
5 4
3 5
4 3
4 3
1 3
3 5
5 4
1 5
3 4
SAMPLE OUTPUT:
9
  */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <math.h>

using namespace std;
const int MAX_N=5e4+1;
bool visited[MAX_N];

int N, K, depth[MAX_N], en[MAX_N], pos[MAX_N], neg[MAX_N], over[MAX_N], rtree[MAX_N], dp[MAX_N][20];
vector<int> tree[MAX_N], leafs;
void depths(int cur, int d, int anc){
  depth[cur] = d;
  visited[cur] = true;
  rtree[cur] = anc;
 // cout << cur << depth[cur] << rtree[cur]  << endl;
  for (int i : tree[cur]){
    int par = false;
    if (!visited[i]) {
      depths(i, d+1, cur);
      par = true;
    }
    if (!par) leafs.push_back(cur);
  }
}

void getends(){
  auto cmp = [](int a, int b){ return depth[a] < depth[b];};
  priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
  bool visited[MAX_N];
  for(int i : leafs) {
    q.push(i);
    visited[i] = true;
  }
  while (!q.empty()){
    int cur = q.top();
   // cout << cur << endl;
    q.pop();
    en[cur] += pos[cur]-over[cur]; //starting points
    cout << en[cur] << ' '<< cur << ' ' << pos[cur] << ' '  << neg[cur] << ' ' << depth[cur] << endl;
    en[rtree[cur]]+=en[cur] - neg[cur];
    if(!visited[rtree[cur]]) {
      q.push(rtree[cur]);
      visited[rtree[cur]] = true;
    }
  }
}


int lca(int i, int j){
  if (depth[i] < depth[j]) swap(i, j);
 // cout << endl << i << j;
  for(int k = (int)log2(N)+1; k>=0; k--){
    if (depth[dp[i][k]] >=depth[j]) i= dp[i][k];
  }
 // cout << i << j;
  if (i==j) return i;

  for(int k = (int)(log2(N))+1; k>=0; k--){
    if (dp[i][k] !=dp[j][k]){
      i = dp[i][k];
      j = dp[j][k];
    }
  }
  return dp[i][0];
}

int main(){
  ifstream fin("maxflow.in");
  ofstream fout("maxflow.out");
  fin >> N >> K;
  for(int i = 0; i < N-1; i++){
    int a, b;
    fin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  depths(1, 0, 1);
  for(int i = 0; i <= N;i++) dp[i][0] = rtree[i];
  for(int i = 1; i < log2(N)+1; i++){
    for(int j = 1; j <= N; j++){
      dp[j][i] = dp[dp[j][i-1]][i-1];
    }
  }
  for(int i = 0; i < K; i++){
    int a, b;
    fin >> a >> b;
    if(depth[b] < depth[a]) swap(a, b);
    int l = lca(b, a);
    cout << l << ' ' << a << ' ' << b << endl;
    if (l==a){
      neg[a]++;
      pos[b]++;
    }
    else {
      over[l]++;
      neg[l]++;
      pos[a]++;
      pos[b]++;
    }
  }
  memset(en, 0, sizeof(en));
  getends();
  int ret = 0;
  for(int i = 1; i <= N; i++) ret = max(ret, en[i]);
  fout << ret;
}
