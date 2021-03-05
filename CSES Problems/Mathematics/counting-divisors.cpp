/*
Given n integers, your task is to report for each integer the number of its divisors.

For example, if x=18, the correct answer is 6 because its divisors are 1,2,3,6,9,18.

Input

The first input line has an integer n: the number of integers.

After this, there are n lines, each containing an integer x.

Output

For each integer, print the number of its divisors.

Constraints
1≤n≤105
1≤x≤106
Example

Input:
3
16
17
18

Output:
5
2
6
*/

#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;

int N;

int count(int a){
  int ans=0;
  for(int i = 1; i < sqrt(a); i++){
    if (a%i == 0) ans++;
  }
  return ans*2+(sqrt(a) == (double)(int)(sqrt(a)));
}

int main(){
  cin >> N;
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    cout << count(a) << '\n'; 
  }
  
  
}
