#include <iostream>
// 使用 using 声明使得 cout 和 endl 在程序中可见
// 也可以分开写, 例如：
// using std::cout;
// using std::endl;
// 注意C++17才支持using std::cin, std::cout;这种形式
// C++11仅支持using std::cin; using std::cout;这种形式（说白了就是仅支持一次只能一个using声明）
using std::cin, std::cout, std::endl;

int main()
{
    int v1 = 0, v2 = 0;
    std::cout << "Input two number: " << std::endl;
    // 考虑输入大小顺序
    std::cin >> v1 >> v2;
    // 输入的是1 5这样的，则升序输出
    if (v2 >= v1)
    {
        while (v1 <= v2)
        {
            std::cout << v1 << " ";
            ++v1;
        }
    }
    // 输入是5 1这样的，降序输出
    else
    {
        while (v1 >= v2)
        {
            std::cout << v1 << " ";
            --v1;
        }
    }
    std::cout << std::endl;
    return 0;
}