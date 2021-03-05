/*Bessie is hoping to fool Farmer John by building a herd of K realistic robotic cows (1≤K≤100,000).
It turns out that building a robotic cow is somewhat complicated. There are N (1≤n≤100,000) individual locations on the robot into which microcontrollers must be connected (so a single microcontroller must be connected at each location). For each of these locations, Bessie can select from a number of different models of microcontroller, each varying in cost.

For the herd of robotic cows to look convincing to Farmer John, no two robots should behave identically. Therefore, no two robots should have exactly the same set of microcontrollers. For any pair of robots, there should be at least one location at which the two robots use a different microcontroller model. It is guaranteed that there will always be enough different microcontroller models to satisfy this constraint.

Bessie wants to make her robotic herd as cheaply as possible. Help her determine the minimum possible cost to do this!

INPUT FORMAT (file roboherd.in):
The first line of input contains N and K separated by a space.
The following N lines contain a description of the different microcontroller models available for each location. The ith such line starts with Mi (1≤Mi≤10), giving the number of models available for location i. This is followed by Mi space separated integers Pi,j giving the costs of these different models (1≤Pi,j≤100,000,000).

OUTPUT FORMAT (file roboherd.out):
Output a single line, giving the minimum cost to construct K robots.
SAMPLE INPUT:
3 10
4 1 5 3 10
3 2 3 3
5 1 3 4 6 6
SAMPLE OUTPUT:
61
Problem credits: Richard Peng and Nathan Pinsker*/

#include <fstream>
#include <set>
#include <algorithm>
using namespace std;
int N, K, costs[100000][10];

struct Cost {
  public:
  int c;
  int x;
  int y;
  Cost (int a, int b, int d){
    c = a;
    x = b;
    y = d;
  }
  bool operator<(const Cost& x) const{
    return c < x.c;
  }
};
multiset<Cost> poss;
int main(){
  ifstream fin("roboherd.in");
  ofstream fout("roboherd.out");
  fin >> N >> K;
  for(int i = 0; i < N; i++){
    int arr[10];
    int n;
    fin >> n;
    for(int j = 0; j<n; j++){
      fin >> arr[j];
    }
    sort(arr, arr+n);
    for(int j = 0; j < n; j++){
      costs[i][j] = arr[j];
    }
  }
  int cur = 0;
  for(int i = 0; i < N; i++){
    cur += costs[i][0];
    if (costs[i][1] > 0) {
      Cost cost = {costs[i][1]-costs[i][0], i, 1};
      poss.insert(cost);
    }
  }
  int ans = cur;
  int num = 1;
  while (num < K){
    Cost rem = *poss.begin();
    cur+=rem.c;
    poss.erase(rem);
    if(rem.y < 9 && costs[rem.x][rem.y+1] > 0){
      Cost cot = {costs[rem.x][rem.y+1] - costs[rem.x][rem.y], rem.x, rem.y+1};
      poss.insert(cot);
    }
    ans += cur;
    num++;
  }
  fout << ans;
}
