// A Hello World program
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    char hello[] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    std::cout << hello << std::endl;
    std::cout << "enter a number less than 22";
    int x;
    cin >> x;
    int y = 0;
    while (x < 22)
    {
        int z = x;
        if (x % 3 == 0)
        {
            for (z; z <= 21; z++)
            {
                std::cout << x / 3 << ' ' << x * 2 << ' ';
                x = x + 6;
            }
        }
        else
        {
            std::cout << "please input valid number, such as:" << y << std::endl;
        }
        x = x + 3;
        y = y + 3;
    }
    std::string s = "insert string with whitespaces here";
    std::stringstream ss(s);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings(begin, end);
    //std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    for (int i = 0; i < vstrings.size(); i++)
    {
        cout << vstrings[i];
    }
    return 0;
}
