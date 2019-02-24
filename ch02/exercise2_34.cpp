#include <iostream>

int main()
{
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;

    std::cout << a << " " << b << " " << c << " "
              << d << " " << e << " " << g << " " << std::endl;

    a = 42;
    b = 42;
    c = 42;
    // d = 42; // 错误：d 是 int *，赋值非法
    // e = 42; // 错误：e 是 const int *，赋值非法
    // g = 42; // 错误：g 是一个常量引用，赋值非法
    std::cout << a << " " << b << " " << c << " "
              << d << " " << e << " " << g << " " << std::endl;
    return 0;
}
