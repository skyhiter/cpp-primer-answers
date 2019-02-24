#include <iostream>
// 如果include了iostream，会发现不用再include string也可以使用std::string，
// 因为iostream里面包含了string，但强烈建议你再次手动include string，
// 避免依赖iostream里面的string
#include <string>

using namespace std;

class Sales_data
{
    // 友元函数，本身不属于该类成员，就是一个普通函数而已，在此声明为友元来访问该类的所有属性
    // >> 运算符重载，二元运算符有两个参数
    // C++的流对象无法复制（这是规定），所以第一个参数要引用（因为不可传值）
    friend std::istream &operator>>(std::istream &, Sales_data &);
    // 输出一般不改变值，所以这里的第二参数需要const
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    friend bool operator<(const Sales_data &, const Sales_data &);
    friend bool operator==(const Sales_data &, const Sales_data &);

  public:
    // 默认构造函数
    Sales_data() = default;
    Sales_data(const std::string &book){};
    // this指针是类的非静态成员函数的第一个参数，指向该对象本身
    Sales_data(std::istream &is) { is >> *this; };
    // += 操作符必须是类成员
    Sales_data &operator+=(const Sales_data &);
    std::string isbn() const { return bookNo; }

  private:
    std::string bookNo;
    unsigned int units_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;
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
    Sales_data ret(lhs);
    ret += rhs;
    return ret;
}

std::istream &operator>>(std::istream &in, Sales_data &s)
{
    in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
    if (in && s.sellingprice != 0)
    {
        s.discount = s.saleprice / s.sellingprice;
    }
    else
    {
        s = Sales_data();
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const Sales_data &s)
{
    out << s.isbn() << " " << s.units_sold << " " << s.sellingprice << " "
        << s.saleprice << " " << s.discount;
    return out;
}

int main()
{
    Sales_data book;
    std::cout << "请输入销售记录：" << std::endl;
    while (std::cin >> book)
    {
        std::cout << "ISBN、销售本书、原始价格、实售价格、折扣为" << book << std::endl;
    }
    Sales_data trans1, trans2;
    std::cout << "请输入两条ISBN相同的销售记录：" << std::endl;
    std::cin >> trans1 >> trans2;
    if (compareIsbn(trans1, trans2))
    {
        std::cout << "汇总信息：ISBN、销售本书、原始价格、实售价格、折扣为 "
                  << trans1 + trans2 << std::endl;
    }
    else
    {
        std::cout << "两条销售记录的ISBN不同" << std::endl;
    }
    Sales_data total, trans;
    std::cout << "请输入几条ISBN相同的销售记录：" << std::endl;
    if (std::cin >> total)
    {
        while (std::cin >> trans)
        {
            if (compareIsbn(total, trans))
                total += trans;
            else
            {
                std::cout << "当前书籍的ISBN不同" << std::endl;
                break;
            }
        }
        std::cout << "有效汇总信息：ISBN、销售本书、原始价格、实售价格、折扣为"
                  << total << std::endl;
    }
    else
    {
        std::cout << "没有数据" << std::endl;
        return -1;
    }

    int num = 1;
    std::cout << "请输入若干销售记录：" << std::endl;
    if (std::cin >> trans1)
    {
        while (std::cin >> trans2)
        {
            if (compareIsbn(trans1, trans2))
            {
                num++;
            }
            else
            {
                std::cout << trans1.isbn() << "共有" << num << "条销售记录" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "没有数据" << std::endl;
        return -1;
    }

    return 0;
}
