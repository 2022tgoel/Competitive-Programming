/*
 *Uncle Bogdan is in captain Flint's crew for a long time and sometimes gets nostalgic for his homeland. Today he told you how his country introduced a happiness index.

There are n cities and n−1 undirected roads connecting pairs of cities. Citizens of any city can reach any other city traveling by these roads. Cities are numbered from 1 to n and the city 1 is a capital. In other words, the country has a tree structure.

There are m citizens living in the country. A pi people live in the i-th city but all of them are working in the capital. At evening all citizens return to their home cities using the shortest paths.

Every person has its own mood: somebody leaves his workplace in good mood but somebody are already in bad mood. Moreover any person can ruin his mood on the way to the hometown. If person is in bad mood he won't improve it.

Happiness detectors are installed in each city to monitor the happiness of each person who visits the city. The detector in the i-th city calculates a happiness index hi as the number of people in good mood minus the number of people in bad mood. Let's say for the simplicity that mood of a person doesn't change inside the city.

Happiness detector is still in development, so there is a probability of a mistake in judging a person's happiness. One late evening, when all citizens successfully returned home, the government asked uncle Bogdan (the best programmer of the country) to check the correctness of the collected happiness indexes.

Uncle Bogdan successfully solved the problem. Can you do the same?

More formally, You need to check: "Is it possible that, after all people return home, for each city i the happiness index will be equal exactly to hi".

Input
The first line contains a single integer t (1≤t≤10000) — the number of test cases.

The first line of each test case contains two integers n and m (1≤n≤105; 0≤m≤109) — the number of cities and citizens.

The second line of each test case contains n integers p1,p2,…,pn (0≤pi≤m; p1+p2+…+pn=m), where pi is the number of people living in the i-th city.

The third line contains n integers h1,h2,…,hn (−109≤hi≤109), where hi is the calculated happiness index of the i-th city.

Next n−1 lines contain description of the roads, one per line. Each line contains two integers xi and yi (1≤xi,yi≤n; xi≠yi), where xi and yi are cities connected by the i-th road.

It's guaranteed that the sum of n from all test cases doesn't exceed 2⋅105.

Output
For each test case, print YES, if the collected data is correct, or NO — otherwise. You can print characters in YES or NO in any case.
  */


#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int T;

int N, M, nump[100001], hap[100001], bad[100001];
vector<int> tree[100001];
bool visited[100001];
int dfs(int cur){
  visited[cur] =  true;
  int peeps = nump[cur];
  for(int i : tree[cur]){
    if (!visited[i]){
      peeps+=dfs(i);
    }
  }
  int good = (hap[cur] + peeps) / 2;
  if (good < 0 || good > peeps || good*2 != hap[cur]+peeps) bad[cur] = -1;
  else bad[cur] = peeps-good;
  return peeps;
}

bool badinc(int cur){
  visited[cur] = true;
  int bads = 0;
  bool works = true;
  bool leaf = true;
  for(int i : tree[cur]){
    if (!visited[i]){
      bads += bad[i];
      works &= badinc(i);
      leaf = false;
    }
  }

  return (leaf || (bad[cur]-nump[cur] <= bads)) && works && bad[cur] != -1;
}

int main(){
  cin >> T;
  for (int i = 0; i < T; i++){
    cin >> N >> M;
    for(int j = 1; j <= N; j++){
      cin >> nump[j];
    }
    for(int j = 1; j <= N; j++){
      cin >> hap[j];
    }
    for(int j = 0; j < N-1; j++){
      int a, b;
      cin >> a >> b;
      tree[a].push_back(b);
      tree[b].push_back(a);
    }
    dfs(1);
    memset(visited, 0, sizeof(visited));
    cout << (badinc(1) ? "YES" : "NO") << endl;
    memset(visited, 0, sizeof(visited));
    memset(tree, 0, sizeof(tree));
  }
}
