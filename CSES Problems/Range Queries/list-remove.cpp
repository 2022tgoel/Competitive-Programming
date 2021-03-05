/*
 * You are given a list consisting of n integers. Your task is to remove elements from the list at given positions, and report the removed elements.

Input

The first input line has an integer n: the initial size of the list. During the process, the elements are numbered 1,2,…,k where k is the current size of the list.

The second line has n integers x1,x2,…,xn: the contents of the list.

The last line has n integers p1,p2,…,pn: the positions of the elements to be removed.

Output

Print the elements in the order they are removed.

Constraints
1≤n≤2⋅105
1≤xi≤109
1≤pi≤n−i+1
Example

Input:
5
2 6 1 4 2
3 1 3 1 1

Output:
1 2 2 6 4

Explanation: The contents of the list are [2,6,1,4,2], [2,6,4,2], [6,4,2], [6,4], [4] and [].
  */

#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 2e5+1;
int n, val[MAX_N], bit[MAX_N];

void update(int i, int v){
  while (i<=n){
    bit[i]+=v;
    i+=(i&-i);
  }
}
int query(int i){
  int ans = 0;
  while (i>0){
    ans+= bit[i];
    i-=(i&-i);
  }
  return ans;
}

int main(){
  memset(bit, 0, sizeof(bit));
  cin >> n;
  for(int i = 1; i <=n; i++) cin >> val[i];
  for(int i = 0; i < n; i++){
    int rem;
    cin >> rem;
    int high = n+1;
    int low = 1;
    while (low < high){
      int mid = (low + high)/2;
      int ind = mid - query(mid);
      if (ind == rem) high = mid;
      if (ind > rem) high = mid;
      if (ind < rem) low = mid+1;
   //   cout << query(mid) << ' ' << ind << endl;
    }
    cout << val[low] << ' ';
    update(low, 1);
  }
}
