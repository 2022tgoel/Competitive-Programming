/*
You are given an array of n positive integers. Your task is to find two integers such that their greatest common divisor is as large as possible.

Input

The first input line has an integer n: the size of the array.

The second line has n integers x1,x2,…,xn: the contents of the array.

Output

Print the maximum greatest common divisor.

Constraints
2≤n≤2⋅105
1≤xi≤106
Example

Input:
5
3 14 15 7 9

Output:
7
*/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_X 1000001
int c[MAX_X];

int main(){
  int N;
  cin >> N;
  memset(c, 0, sizeof(c));

  for(int i = 0 ; i < N;i ++) {
    int x;
    cin >> x;
    c[x]++;
  }

  for(int i=MAX_X; i>=1; i--){
    int numdiv = 0;
    for(int j = i; j<=MAX_X; j+=i){
      numdiv+=c[j];
      
    }
    if (numdiv > 1){
      cout << i;
      break;
    }
  }
}
