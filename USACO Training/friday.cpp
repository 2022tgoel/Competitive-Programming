/*
ID: tishi.t1
PROG: friday
LANG: C++
*/

#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

bool leapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year == 2000)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ofstream fout("output.out");
    ifstream fin("input.txt");
    string input;
    fin >> input;
    int time = atoi(input.c_str());
    int answer[7] = {0, 0, 0, 0, 0, 0, 0};
    int day = 2;
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leapDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int year = 1900; year < 1900 + time; year++)
    {
        for (int month = 0; month < 12; month++)
        {
            int thirteen = (day + 12) % 7;
            answer[thirteen]++;
            if (leapYear(year))
            {
                day = (day + leapDays[month]) % 7;
            }
            else
            {
                day = (day + monthDays[month]) % 7;
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        fout << answer[i];
        if (i == 6)
        {
            fout << endl;
        }
        else
        {
            fout << " ";
        }
    }
    return 0;
}