#include <iostream>
#include <typeinfo> // 需要里面的type_info class

// C++17 才支持 using std::cout, std::endl;
using std::cout;
using std::endl;

int main()
{
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    // typeid是C++的关键字，返回的是type_info class
    // .name()是c-string风格的字符串，不同编译器的name不同，比如
    // clang/GUN g++中的int类型对应的.name()就是i; visual C++ 就是int
    cout << "val j: " << typeid(j).name() << endl;
    cout << "val k: " << typeid(k).name() << endl;
    cout << "val p: " << typeid(p).name() << endl;
    cout << "val j2: " << typeid(j2).name() << endl;
    cout << "val k2: " << typeid(k2).name() << endl;

    return 0;
}
