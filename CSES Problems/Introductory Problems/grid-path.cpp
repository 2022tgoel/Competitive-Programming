/*
There are 88418 paths in a 7×7 grid from the upper-left square to the lower-left square. Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).

For example, the path

corresponds to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.

You are given a description of a path which may also contain characters ? (any direction). Your task is to calculate the number of paths that match the description.

Input

The only input line has a 48-character string of characters ?, D, U, L and R.

Output

Print one integer: the total number of paths.

Example

Input:
??????R??????U??????????????????????????LD????D?

Output:
201
*/

#include <iostream>
#include <cstring>
using namespace std;
int ans = 0;
string path;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};
bool visit[7][7];
bool poss(int r, int c){
  return !visit[r][c] && r >=0 && c>=0 && r < 7 && c <7;
}
void dfs(int r, int c, int len){
  //ways that no path exists from here to 6,0
  if (poss(r+1, c) && poss(r-1, c) && !poss(r, c-1) && !poss(r, c+1)){
    visit[r][c] = false;
    return;
  }
  if (!poss(r+1, c) && !poss(r-1, c) && poss(r, c-1) && poss(r, c+1)){
    visit[r][c] = false;
    return;
  }
  if (abs(r-6) + abs(c-0) + len > 48) {
    visit[r][c] = false;
    return;
  }
  if (r == 6 && c==0) {
    if (len == 48) ans++;
    return;
  }
  visit[r][c] = true;
  if (path.at(len)!='?'){
    int nr, nc = 0;
    if(path.at(len) == 'D'){
      nr = r+1;
      nc = c;
    }
    if(path.at(len) == 'U'){
      nr = r-1;
      nc = c;
    }
    if(path.at(len) == 'R'){
      nr = r;
      nc = c+1;
    }
    if(path.at(len) == 'L'){
      nr = r;
      nc = c-1;
    }
    if (!poss(nr, nc)) {
      visit[r][c] = false;
      return;
    }
    dfs(nr, nc, len+1);
  }
  else {        
    for(int i = 0; i < 4; i++){
      int nr = r + dx[i];
      int nc = c + dy[i];
      if (!poss(nr, nc)) continue;
      dfs(nr, nc, len+1);
    }
  }
  //cout << r << c;
  visit[r][c] = false;
  return;
}

int main(){
  memset(visit, 0, sizeof(visit));
  cin >> path;
  dfs(0, 0, 0);
  cout << ans;
}
	    
