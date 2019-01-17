## 练习2.1

> 类型 int、long、long long 和 short 的区别是什么？无符号类型和带符号类型的区别是什么？float 和 double的区别是什么？

在C++语言中，int、long、long long 和 short 都属于整型，区别在于C++标准规定的尺寸的最小值（平台实现可以大点但不能更小）不同。其中，short 是16位，int 是16位，long 是32位，long long 是64位，C++标准允许不同的编译器实现的更大一些。

大多数整型可以分为有符号和无符号。无符号的是所有bit都用来存储数值，仅表示正整数和0；有符号的可以表示正数、负数和0.

float 和 double 分别是单精度和双精度浮点数，float 是32位，7位有效数字；double 是64位，16位有效数字。

用法：

* 一般使用 int 做整数运算，short 因为太小在实际中用的少，long 通常和 int 有着相同的大小。如果数据非常大，可以使用 long long。
* 如果你确认数据是非负的，那么就使用 unsigned 无符号类型。
* **执行浮点运算时尽量要用 double** ，因为 float 通常精度不够而且双精度浮点数和单精度浮点数的计算代价相差无几（当然嵌入式领域除外）。
  
编注：

在我的机器（macOS10.14/Centos7.5）上测试数据类型大小为（使用`sizeof()`）：

| 类型      | 字节 | 比特  |
| --------- | ---: | :---: |
| short     |    2 |  16   |
| int       |    4 |  32   |
| long      |    8 |  64   |
| long long |    8 |  64   |


参考：

- [What are the criteria for choosing between short / int / long data types?](http://www.cs.technion.ac.il/users/yechiel/c++-faq/choosing-int-size.html)
- [Difference between float and double](https://stackoverflow.com/questions/2386772/what-is-the-difference-between-float-and-double)

## 练习2.2
> 计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

**如果要用到浮点数，尽可能用`double`**。因为`float`精度太低了，只有7位有效数字，而且`float`和`double`的运算速度差不多。在嵌入式领域才可能会考虑使用`float`，因为嵌入式系统的资源很匮乏，空间能省就省。

所以这里的利率、本金和付款都要用`double`。

## 练习2.3

> 读程序写结果。

```C++
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;

int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

输出：

我的编译环境`int`是32位。

```
1. 32
2. 4294967264
3. 32
4. -32
5. 0
6. 0
```

解释：

在计算机里，一切数值都是补码存储，比如无符号数`1`在内存中是补码形式(1的补码还是1)的二进制，有符号数`-1`在内存中也是补码形式(-1的补码是另一个很大的数)的二进制，各种运算都是以这种补码运算的。

无符号数减无符号数还是无符号数，所以`u - u2`应该也是无符号数。因为`u - u2 = -32`，所以要把`-32`看作无符号数。在计算机里，一切数值都是补码存储，`-32`在内存中就是补码(FF FF FF E0)的形式存在的，将FF FF FF E0看作是无符号的话，就是4294967264。

有符号数减无符号数会先把有符号转为无符号数，再相减。所以`i - u`自动转为了`unsigned i - unsigned u`，对于 int 10 来说，其 unsigned 的形式也是10，所以相减是0.

## 练习2.4

> 编写程序检查你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在。

略。

## 练习2.5

> 指出下述字面值的数据类型并说明每一组内几种字面值的区别：
- (a) 'a', L'a', "a", L"a"
- (b) 10, 10u, 10L, 10uL, 012, 0xC
- (c) 3.14, 3.14f, 3.14L
- (d) 10, 10u, 10., 10e-2

答案：

- (a) 'a'是普通的字符字面值, L'a'是wchar_t类型, "a"是字符串字面值, L"a"是宽字符串字面值。
- (b) 10就是普通的十进制有符号数10, 10u是十进制无符号数10, 10L是十进制有符号数Long类型的整型10, 10uL是十进制无符号数Long类型的无符号整型10, 012是八进制整型, 0xC是十六进制整型。
- (c) 3.14是double, 3.14f是float, 3.14L是long double。
- (d) 10是十进制整型, 10u是十进制无符号整型, 10.是double, 10e-2是double（科学计数法的形式，即$10 \times 10^{-2}$）。

## 练习2.6

> 下面两组定义是否有区别，如果有，请叙述之：

```C++
int month = 9, day = 7;
int month = 09, day = 07;
```

第一行都是十进制数，第二行都是八进制数（0开头）。但是`09`这种写法是不对的，因为八进制数没有9，所以编译器报错`invalid digit '9' in octal constant`。

## 练习2.7

> 下述字面值表示何种含义？它们各自的数据类型是什么？

```C++
(a) "Who goes with F\145rgus?\012"
(b) 3.14e1L
(c) 1024f
(d) 3.14L
```

- (a) 带转义符的字符串字面值。`\145`是转义符，其中145是八进制，转为十进制就是101，对应ASCII表的`e`；`\012`同理，12的十进制是10，对应ASCII表的`LF`(换行)。原字符串等价于"Who goes with Fergus?(换行)"。
- (b) long double类型，且是科学计数法形式，$3.14\times10^{1}$.
- (c) 后缀`f`说明是float，也就是说`f`前面必须是带小数点的。但是前面是整型，所以会报错`invalid digit 'f' in decimal constant`。可以改为`1024.f`就好了。
- (d) long double.
  
## 练习2.8

> 请利用转义序列编写一段程序，要求先输出 2M，然后转到新一行。修改程序使其先输出 2，然后输出制表符，再输出 M，最后转到新一行。

```C++
#include <iostream>

int main()
{
    // 2 的 ASCII 十六进制 32
    // M 的 ASCII 十六进制 4D
    // 换行(LF,\n) 的 ASCII 十六进制 0A
    // 水平制表符(HT,\t) 的 ASCII 十六进制 09
    std::cout << "\x32\x4d\x0a";
    std::cout << "\x32\x09\x4d\x0a";
    return 0;
}
```

## 练习2.9

> 解释下列定义的含义，对于非法的定义，请说明错在何处并将其改正。

```C++
(a) std::cin >> int input_value;
(b) int i = { 3.14 };
(c) double salary = wage = 9999.99;
(d) int i = 3.14;
```

