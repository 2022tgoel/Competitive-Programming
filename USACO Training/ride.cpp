/*
ID: tishi.t1
PROG: ride
LANG: C++
*/
// solution to: http://train.usaco.org/usacoprob2?a=CCZOylmiTPj&S=ride
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int findValue(string name)
{
    int l = name.size();
    int numname[l];
    int val = 1;
    for (int i = 0; i < l; i++)
    {
        numname[i] = (int)name.at(i) - 64;
    }
    for (int j = 0; j < l; j++)
    {
        val = val * numname[j];
    }
    return val % 47;
}

int main()
{
    string read;
    std::vector<string> names;
    ifstream inFile;
    ofstream outFile;
    inFile.open("input.txt");
    if (!inFile)
    {
        cerr << "Unable to open file";
        exit(1); // call system to stop
    }
    while (inFile >> read)
    {
        names.push_back(read);
    }
    inFile.close();
    outFile.open("output.out");
    if (findValue(names[0]) == findValue(names[1]))
    {
        outFile << "GO" << "\n";
    }
    else
    {
        outFile << "STAY" << "\n";
    }
    outFile.close();

    return 0;
}
