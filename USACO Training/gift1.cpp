/*
ID: tishi.t1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
  ofstream fout("output.out");
  ifstream fin("input.txt");
  int NP;
  fin >> NP;
  string names[NP];
  for (int i = 0; i < NP; i++)
  {
    fin >> names[i];
  }
  int holdings[NP];
  int gifts[NP];
  for (int j = 0; j < NP; j++)
  {
    holdings[j] = 0;
    gifts[j] = 0;
  }
  int money[NP], loc[NP], friends[NP];
  string name[NP];
  for (int k = 0; k < NP; k++)
  {
    fin >> name[k];
    for (int m = 0; m < NP; m++)
    {
      if (names[m] == name[k])
      {
        loc[k] = m;
      }
    }
    fin >> money[k] >> friends[k];
    if (friends[k] == 0)
    {
    }
    else
    {
      int holder = 0;
      holder += money[k];
      holdings[loc[k]] = holder;
      string friendies[friends[k]];
      if (money[k] % friends[k] == 0)
      {
        money[k] /= friends[k];
      }
      else
      {
        gifts[loc[k]] += money[k] % friends[k];
        money[k] -= money[k] % friends[k];
        money[k] /= friends[k];
      }
      for (int n = 0; n < friends[k]; n++)
      {
        fin >> friendies[n];
      }
      for (int p = 0; p < NP; p++)
      {
        for (int r = 0; r < friends[k]; r++)
        {
          if (names[p] == friendies[r])
          {
            gifts[p] += money[k];
          }
        }
      }
    }
  }
  for (int s = 0; s < NP; s++)
  {
    fout << names[s] << " " << gifts[s] - holdings[s] << endl;
  }

  return 0;
}