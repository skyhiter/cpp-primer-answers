#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    // 因为要改变原string的值，这里需要用引用
    for (auto &c : str)
    {
        c = 'X';
    }
    cout << str << endl;

    return 0;
}
