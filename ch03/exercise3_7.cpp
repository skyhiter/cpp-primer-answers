#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    for (char c : str)
    {
        c = 'X';
    }
    cout << str << endl;

    return 0;
}
