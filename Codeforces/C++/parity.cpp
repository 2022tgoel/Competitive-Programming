/*
 * E. Nearest Opposite Parity
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a consisting of n integers. In one move, you can jump from the position i to the position i−ai (if 1≤i−ai) or to the position i+ai (if i+ai≤n).

For each position i from 1 to n you want to know the minimum the number of moves required to reach any position j such that aj has the opposite parity from ai (i.e. if ai is odd then aj has to be even and vice versa).

Input
The first line of the input contains one integer n (1≤n≤2⋅105) — the number of elements in a.

The second line of the input contains n integers a1,a2,…,an (1≤ai≤n), where ai is the i-th element of a.

Output
Print n integers d1,d2,…,dn, where di is the minimum the number of moves required to reach any position j such that aj has the opposite parity from ai (i.e. if ai is odd then aj has to be even and vice versa) or -1 if it is impossible to reach such a position.
*/

#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[200000];
int N, a[200000], ans[200000];
set<pair<int, int>> edges;
queue<int> groups;
int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  for(int i = 0; i < N; i++){
    if (i - a[i] >= 0){
      edges.emplace(make_pair(i-a[i], i));
      graph[i-a[i]].push_back(i);
    }
    if (i + a[i] < N){
      edges.insert(make_pair(i+a[i], i));
      graph[i+a[i]].push_back(i);
    }
  }
  for (pair<int, int> edge : edges){
    if (a[edge.first] % 2 != a[edge.second] % 2) {
      ans[edge.second] = 1;
      groups.push(edge.second);
    }
  }
  while (!groups.empty()){
    int cur = groups.front();
    groups.pop();
    for (int i : graph[cur]){
      if (ans[i] == 0){
        groups.push(i);
        ans[i] = ans[cur] + 1;
      }
    }
  }
  for (int i = 0; i < N; i++){
    cout << ((ans[i] > 0) ? ans[i] : -1) << ' ';
  }
}
