## 练习2.1

> 类型 int、long、long long 和 short 的区别是什么？无符号类型和带符号类型的区别是什么？float 和 double的区别是什么？

在C++语言中，int、long、long long 和 short 都属于整型，区别在于C++标准规定的尺寸的最小值（平台实现可以大点但不能更小）不同。其中，short 是16位，int 是16位，long 是32位，long long 是64位，C++标准允许不同的编译器实现的更大一些。

大多数整型可以分为有符号和无符号。无符号的是所有bit都用来存储数值，仅表示正整数和0；有符号的可以表示正数、负数和0.

float 和 double 分别是单精度和双精度浮点数，float 是32位，7位有效数字；double 是64位，16位有效数字。

用法：

* 一般使用 int 做整数运算，short 因为太小在实际中用的少，long 通常和 int 有着相同的大小。如果数据非常大，可以使用 long long。
* 如果你确认数据是非负的，那么就使用 unsigned 无符号类型。
* **执行浮点运算时尽量要用 double** ，因为 float 通常精度不够而且双精度浮点数和单精度浮点数的计算代价相差无几（当然嵌入式领域除外）。
  
编注：

在我的机器（macOS10.14/Centos7.5）上测试数据类型大小为：

1. short      16 位
2. int        32 位
3. long       64 位
4. long long  64 位
  
参考：

- [What are the criteria for choosing between short / int / long data types?](http://www.cs.technion.ac.il/users/yechiel/c++-faq/choosing-int-size.html)
- [Difference between float and double](https://stackoverflow.com/questions/2386772/what-is-the-difference-between-float-and-double)

## 练习2.2
> 计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

如果要用到浮点数，尽可能用`double`。因为`float`精度太低了，只有7位有效数字，而且`float`和`double`的运算速度差不多。在嵌入式领域才可能会考虑使用`float`，因为嵌入式系统的资源很匮乏，空间能省就省。

所以这里的利率、本金和付款都要用`double`。