#include <iostream>
#include <string>

// struct默认是共有的，class默认是私有的
// 除此之外，struct与class大同小异
struct Sales_data
{
    std::string bookNo;          // 书籍编号
    std::string bookName;        // 书名
    unsigned int units_sold = 0; // 销售量
    double revenue = 0.0;        // 销售收入
    double sellingprice = 0.0;   // 零售价
    double saleprice = 0.0;      // 实售价
    double discount = 0.0;       // 折扣，按 discount = saleprice / sellingprice 计算
};

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
