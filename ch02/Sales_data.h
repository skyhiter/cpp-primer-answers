#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED

// 头文件的文件名 最好与该本文件的类的名字一致, 不一致似乎也没问题
// 但是 "一致" 是一种强烈的建议

#include <iostream>
// 如果include了iostream，会发现不用再include string也可以使用std::string，
// 因为iostream里面包含了string，但强烈建议你再次手动include string，
// 避免依赖iostream里面的string
#include <string>

class Sales_data
{
    // 友元函数，本身不属于该类成员，就是一个普通函数而已，在此声明为友元来访问该类的所有属性
    // >> 运算符重载，二元运算符重载（非类成员的运算符）有两个参数
    // C++的流对象无法复制（这是规定），所以第一个参数要引用（因为不可传值）
    // 输入输出流操作符重载一般不能设置为类成员，需要放在外部然后设置为类的友元函数，以便访问类的私有成员
    friend std::istream &operator>>(std::istream &, Sales_data &);
    // 输出一般不改变值，所以这里的第二参数需要const
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    // 函数输入不变的需要设为const
    friend bool operator<(const Sales_data &, const Sales_data &);
    friend bool operator==(const Sales_data &, const Sales_data &);

  public:
    // 默认构造函数
    Sales_data() = default;
    Sales_data(const std::string &book):bookNo(book){};
    // this指针是类的非静态成员函数的第一个参数，指向该对象本身
    Sales_data(std::istream &is) { is >> *this; };
    // += 操作符必须是类成员，类成员的操作符重载参数少一个（少的是第一个参数this，省略了）
    Sales_data &operator+=(const Sales_data &);
    std::string isbn() const { return bookNo; }

  private:
    std::string bookNo;          // ISBN号，隐式初始化为空串
    unsigned int units_sold = 0; // 销售量，显式初始化为 0
    double sellingprice = 0.0;   // 零售价，显式初始化为 0.0
    double saleprice = 0.0;      // 实售价(折扣价)
    double discount = 0.0;       // 折扣(打几折), discount = saleprice / sellingprice
};

// lhs 是 left hand side 的缩写，表示左操作数，编程领域经常用到该缩写
inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}

// 函数只是声明而未实现函数体时，参数名可省略，只写类型就好
Sales_data operator+(const Sales_data &, const Sales_data &);

// 函数operator==()是类的友元函数，所以该函数可以访问类的私有成员，
// 否则，普通的外部函数是无法访问类的private的成员的
inline bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn() &&
           lhs.units_sold == rhs.units_sold &&
           lhs.sellingprice == rhs.sellingprice &&
           lhs.saleprice == rhs.saleprice;
}

inline bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs); // 这里 != 运算是借用 == 运算来实现的，前面已经重载完成了 ==
}

// += 重载函数是类的成员函数, 所以可任意访问类的数据
Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    saleprice = (saleprice * units_sold + rhs.saleprice * rhs.units_sold) / (units_sold + rhs.units_sold);
    if (sellingprice != 0)
    {
        discount = saleprice / sellingprice;
    }
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    // 这个形式是直接初始化的意思，会调用拷贝构造函数
    // 如果类没有自己的写的拷贝构造函数，编译器会自动创建一个
    // 如果 Sales_data ret = lhs; 则是拷贝初始化
    Sales_data ret(lhs);
    ret += rhs;
    return ret;
}

std::istream &operator>>(std::istream &in, Sales_data &s)
{
    // 默认的 >> 操作符已经重载了内置数据类型和标准库类(如string)
    in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
    if (in && s.sellingprice != 0)
    {
        s.discount = s.saleprice / s.sellingprice;
    }
    else
    {
        s = Sales_data();
    }
    // >> 返回本身
    return in;
}

std::ostream &operator<<(std::ostream &out, const Sales_data &s)
{
    out << s.isbn() << " " << s.units_sold << " " << s.sellingprice << " "
        << s.saleprice << " " << s.discount;
    return out;
}

#endif // SALES_DATA_H_INCLUDED