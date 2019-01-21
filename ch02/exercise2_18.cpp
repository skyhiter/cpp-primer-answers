#include <iostream>

int main()
{
    int i = 0;
    int *p = &i;
    // 打印原始信息
    std::cout << "original\ti: " << i << "\t"
              << "p: " << p << "\t"
              << "*p: " << *p << std::endl;

    // 改变 p 指向的变量的值
    *p = 1;
    std::cout << "new 1\ti: " << i << "\t"
              << "p: " << p << "\t"
              << "*p: " << *p << std::endl;

    // 改变指针本身，即让 p 重新指向别的变量
    int j = 2;
    p = &j;
    std::cout << "new 2\tj: " << j << "\t"
              << "p: " << p << "\t"
              << "*p: " << *p << std::endl;

    // 通过直接修改目的变量的值，间接改变 *p
    j = 3;
    std::cout << "new 3\tj: " << j << "\t"
              << "p: " << p << "\t"
              << "*p: " << *p << std::endl;
    return 0;
}
