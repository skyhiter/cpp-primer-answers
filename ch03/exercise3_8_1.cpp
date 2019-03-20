#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    decltype(str.size()) i = 0;
    while (i != str.size())
    {
        str[i] = 'X';
        ++i;
    }
    cout << str << endl;

    return 0;
}
