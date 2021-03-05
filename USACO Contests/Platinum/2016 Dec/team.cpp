/*
 *Every year, Farmer John brings his N cows to compete for "best in show" at the state fair. His arch-rival, Farmer Paul, brings his M cows to compete as well (1≤N≤1000,1≤M≤1000).
Each of the N+M cows at the event receive an individual integer score. However, the final competition this year will be determined based on teams of K cows (1≤K≤10), as follows: Farmer John and Farmer Paul both select teams of K of their respective cows to compete. The cows on these two teams are then paired off: the highest-scoring cow on FJ's team is paired with the highest-scoring cow on FP's team, the second-highest-scoring cow on FJ's team is paired with the second-highest-scoring cow on FP's team, and so on. FJ wins if in each of these pairs, his cow has the higher score.

Please help FJ count the number of different ways he and FP can choose their teams such that FJ will win the contest. That is, each distinct pair (set of K cows for FJ, set of K cows for FP) where FJ wins should be counted. Print your answer modulo 1,000,000,009.

INPUT FORMAT (file team.in):
The first line of input contains N, M, and K. The value of K will be no larger than N or M.
The next line contains the N scores of FJ's cows.

The final line contains the M scores of FP's cows.

OUTPUT FORMAT (file team.out):
Print the number of ways FJ and FP can pick teams such that FJ wins, modulo 1,000,000,009.
SAMPLE INPUT:
10 10 3
1 2 2 6 6 7 8 9 14 17
1 3 8 10 10 16 16 18 19 19
SAMPLE OUTPUT:
382
Problem credits: Brian Dean and William Luo
  */

#include <fstream>
#include <algorithm>
using namespace std;
int N, M, K;
long long dp[1000][1000][11], bit[1001][1001];
long long john[1000], paul[1000];
const int MOD = 1e9+9;
void update(int i, int j, int k){
  int val = dp[i-1][j-1][k] - dp[i-1][j-1][k-1]; // total change it this value
  int r = i;
  while (r <= N){
    int c = j;
    while (c <= M){
      bit[r][c] = ((bit[r][c] + val) % MOD);
      c+=(c&-c);
    }
    r+=(r&-r);
  }
}

long long qry(int i, int j){
  long long ans = 0;
  int c = j;
  while(i > 0){
    j = c;
    while (j > 0){
      ans =  ((ans + bit[i][j]) % MOD);
      j -= (j&-j);

    }
    i-=(i&-i);
  }
  return ans;
}

int main(){
  ifstream fin("team.in");
  ofstream fout("team.out");
  fin >> N >> M >> K;
  for(int i = 0; i < N; i++){
    fin >> john[i];
  }
  for(int i = 0 ; i < M ; i++){
    fin >> paul[i];
  }
  sort(john, john+N);
  sort(paul, paul+M);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if (john[i] > paul[j]) {
        dp[i][j][1] = 1;
        update(i+1, j+1, 1);
      }
    }
  }
  for(int k = 2; k<=K; k++){
    for(int i = 0 ; i < N ; i++){
      for(int j = 0; j < M; j++){
        if(john[i] > paul[j]){
          dp[i][j][k] = qry(i, j);
        }
      }
    }
    for(int i = 0 ; i < N ; i++){
      for(int j = 0; j < M; j++){
        update(i+1, j+1, k);
      }
    }
  }
  fout << qry(N, M);
}
