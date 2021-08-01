/*
 * There are n hotels on a street. For each hotel you know the number of free rooms. Your task is to assign hotel rooms for groups of tourists. All members of a group want to stay in the same hotel.

The groups will come to you one after another, and you know for each group the number of rooms it requires. You always assign a group to the first hotel having enough rooms. After this, the number of free rooms in the hotel decreases.

Input

The first input line contains two integers n and m: the number of hotels and the number of groups. The hotels are numbered 1,2,…,n.

The next line contains n integers h1,h2,…,hn: the number of free rooms in each hotel.

The last line contains m integers r1,r2,…,rm: the number of rooms each group requires.

Output

Print the assigned hotel for each group. If a group cannot be assigned a hotel, print 0 instead.

Constraints
1≤n,m≤2⋅105
1≤hi≤109
1≤ri≤109
Example

Input:
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1

Output:
3 5 0 1 1
  */

#include <iostream>

using namespace std;
const int MAX_N = 2e5;
int n, m, st[4*MAX_N], arr[MAX_N];

void build(int i, int l, int r){
  if (l==r) {
    st[i] = arr[l];
    return;
  }
  int next = i << 1;
  int mid = (l+r)/2;
  build(next, l, mid);
  build(next+1, mid+1, r);
  st[i] = max(st[next], st[next+1]);
  return;
}
void update(int i, int l, int r, int k, int u){
  if (k < l || k > r) return;
  if (l==r) {
    st[i] = u;
    return;
  }
  int next = i << 1;
  int mid = (l+r)/2;
  update(next, l, mid, k, u);
  update(next+1, mid+1, r, k, u);
  st[i] = max(st[next], st[next+1]);
  return;
}
int qry(int i, int l , int r, int a, int b){
  if (l > b || r < a) return 0;
  if (a<= l && r <= b) return st[i];
  int next = i << 1;
  int mid = (l+r)/2;
  return max(qry(next, l, mid, a, b), qry(next+1, mid+1, r, a, b));
}

int main(){
  cin >> n >> m;
  for(int i = 0; i< n; i++ ) cin >> arr[i];
  build(1, 0, n-1);
  for(int i = 0; i < m; i++) {
    int cap;
    cin >> cap;
    if (cap > st[1]){
      cout << "0 ";
      continue;
    }
    int low = 0;
    int high = n-1;
    while (low < high){
      int mid = (high+low)/2;
      bool works = (qry(1, 0, n-1, 0, mid) >= cap);
      works ? high = mid : low = mid+1;
    }
    cout << high+1 << ' ';
    arr[high]-=cap;
    update(1, 0, n-1, high, arr[high]);
  }
  cout << endl;
}
