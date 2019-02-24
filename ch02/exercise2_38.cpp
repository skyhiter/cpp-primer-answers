#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int a = 1;
    auto b = a; // a 是 int， 所以 auto b 也是 int
    decltype(a) c = a; // a 是 int，所以 decltype(a) 也是 int
    decltype((a)) d = a; // 加了括号 (a)就会变成引用类型，所以 decltype((a)) 是 int &，所以d是a的别名
    cout << a << " " << b << " " << c << " " << d << endl;
    ++b; // int 
    ++c; // int
    ++d; // int &, d 绑定到了 a, d 自增导致 a 也自增
    cout << a << " " << b << " " << c << " " << d << endl;
    cout << endl;

    const int a2 = 1;
    auto b2 = a2; // a2 是顶层 const, auto b2 推断会去掉顶层 const，所以 b2 是 int
    decltype(a2) c2 = a2; // decltype(a2) 就是 a2 的类型, 即 const int
    decltype((a2)) d2 = a2; // 加了括号就是引用类型了, 即 const int &
    cout << a2 << " " << b2 << " " << c2 << " " << d2 << endl;
    ++b2;
    // ++c2; // clang error: cannot assign to variable 'c2' with const-qualified type 'decltype(a2)' (aka 'const int')
    // ++d2; // clang error: cannot assign to variable 'd2' with const-qualified type 'decltype((a2))' (aka 'const int &')
    cout << a2 << " " << b2 << " " << c2 << " " << d2 << endl;
    return 0;
}
