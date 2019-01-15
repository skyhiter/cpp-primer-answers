#include <iostream>

int main()
{
    /*
    * 注释对/* */不能嵌套。
    * “不能嵌套”这几个字会被认为是源码，
    * 像剩余程序一样处理
    */
    std::cout << "hello, world" << std::endl;
    return 0;
}