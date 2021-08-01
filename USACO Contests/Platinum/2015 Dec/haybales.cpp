/*
 * Farmer John is trying to hire contractors to help rearrange his farm, but so far all of them have quit when they saw the complicated sequence of instructions FJ wanted them to follow. Left to complete the project by himself, he realizes that indeed, he has made the project perhaps more complicated than necessary. Please help him follow his instructions to complete the farm upgrade.
FJ's farm consists of N fields in a row, conveniently numbered 1…N. In each field there can be any number of haybales. Farmer John's instructions contain three types of entries:

1) Given a contiguous interval of fields, add a new haybale to each field.

2) Given a contiguous interval of fields, determine the minimum number of haybales in a field within that interval.

3) Given a contiguous interval of fields, count the total number of haybales inside that interval.

INPUT FORMAT (file haybales.in):
The first line contains two positive integers, N (1≤N≤200,000) and Q (1≤Q≤100,000).
The next line contains N nonnegative integers, each at most 100,000, indicating how many haybales are initially in each field.

Each of the next Q lines contains a single uppercase letter, either M, P or S, followed by either two positive integers A and B (1≤A≤B≤N), or three positive integers A, B, and C (1≤A≤B≤N; 1≤C≤100,000). There will be three positive integers if and only if the uppercase letter is P.

If the letter is M, print the minimum number of haybales in the interval of fields from A…B.

If the letter is P, put C new haybales in each field in the interval of fields from A…B.

If the letter is S, print the total number of haybales found within interval of fields from A…B.

OUTPUT FORMAT (file haybales.out):
A line in the output should appear in response to every 'M' or 'S' entry in FJ's instructions.
SAMPLE INPUT:
4 5
3 1 2 4
M 3 4
S 1 3
P 2 3 1
M 3 4
S 1 3
SAMPLE OUTPUT:
2
6
3
8
  */

#include <iostream>
#include <fstream>
using namespace std;
const int MAX_N = 2e5;
#define ll long long
ll N, Q, arr[MAX_N], mint[4*MAX_N], lazy[4*MAX_N], sumt[4*MAX_N];

void build(int k, int l, int r){
  lazy[k] = 0;
  if (l == r) {
    mint[k] = arr[l];
    sumt[k] = arr[l];
    return;
  }
  int n = k << 1;
  int mid = (l+r)/2;
  build(n, l, mid);
  build(n+1, mid+1, r);
  mint[k] = min(mint[n], mint[n+1]);
  sumt[k] = sumt[n] + sumt[n+1];
  return;
}

void lazyprop(int k, ll u, int l, int r){
  mint[k] += u;
  sumt[k] += (r-l+1)*u;
  lazy[k] = 0;
  if (l == r) return;
  lazy[k << 1] += u;
  lazy[(k << 1) + 1] +=u;
}

void upd(int k, int l, int r, int a, int b, int c){
  lazyprop(k, lazy[k], l, r);
  if (l > b || r < a) return;
  if (a<=l && r<=b){
    lazyprop(k, c, l, r);
    return;
  }
  int n = k << 1;
  int mid = (l+r)/2;
  upd(n, l, mid, a, b, c);
  upd(n+1, mid+1, r, a, b, c);
  mint[k] = min(mint[n], mint[n+1]);
  sumt[k] = sumt[n] + sumt[n+1];
}

ll min_qry(int k, int l, int r, int a, int b){
  lazyprop(k, lazy[k], l, r);
  if (l > b || r < a) return 1e15;
  if (a <=l && r <=b) return mint[k];
  int n = k << 1;
  int mid = (l+r)/2;
  return min(min_qry(n, l, mid, a, b), min_qry(n+1, mid+1, r, a, b));
}
ll sum_qry(int k, int l , int r, int a, int b){
  lazyprop(k, lazy[k], l, r);
  if (l > b || r < a) return 0;
  if (a<= l && r<=b){
    return sumt[k];
  }
  int n = k << 1;
  int mid = (l+r)/2;
  return sum_qry(n, l, mid, a, b) + sum_qry(n+1, mid+1, r, a, b);
}

int main(){
  ifstream cin("haybales.in");
  ofstream cout("haybales.out");
  cin >> N >> Q;
  for(int i = 0; i < N ;i++) cin >> arr[i];
  build(1, 0, N-1);
  for(int i = 0; i < Q; i++){
    char cmd;
    cin >> cmd;
    if (cmd == 'M'){
      int l, r;
      cin >> l >> r;
      cout << min_qry(1, 0, N-1, l-1, r-1) << endl;
    }
    if (cmd == 'S'){
      int l, r;
      cin >> l >> r;
      cout << sum_qry(1, 0, N-1, l-1, r-1) << endl;
    }
    if (cmd == 'P'){
      int l, r, u;
      cin >> l >> r >> u;
      upd(1, 0, N-1, l-1, r-1, u);
    }
  }

}
