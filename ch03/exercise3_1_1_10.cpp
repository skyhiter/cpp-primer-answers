#include <iostream>
// 使用 using 声明使得 cout 和 endl 在程序中可见
// 也可以分开写, 例如：
// using std::cout;
// using std::endl;
using std::cout, std::endl;

int main()
{
    int start = 10;
    while (start >= 0)
    {
        cout << start << endl;
        --start;
    }
    return 0;
}