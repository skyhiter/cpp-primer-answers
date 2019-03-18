#include <iostream>
// 使用 using 声明使得 cout 和 endl 在程序中可见
// 也可以分开写, 例如：
// using std::cout;
// using std::endl;
// 注意C++17才支持using std::cin, std::cout;这种形式
// C++11仅支持using std::cin; using std::cout;这种形式（说白了就是仅支持一次只能一个using声明）
using std::cout, std::endl;

int main()
{
    int sum = 0, start = 50;
    while (start <= 100)
    {
        sum += start;
        ++start;
    }
    cout << "sum is " << sum << endl;
    return 0;
}