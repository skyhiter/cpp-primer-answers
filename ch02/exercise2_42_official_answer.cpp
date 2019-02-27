#include <iostream>
#include "Sales_data.h"

int main()
{
    // P20 练习1.20
    // 读取一组销售记录，并打印出来
    Sales_data book;
    std::cout << "请输入销售记录：" << std::endl;
    while (std::cin >> book)
    {
        std::cout << "ISBN、销售本书、原始价格、实售价格、折扣为 " << book << std::endl;
    }


    // P20 练习1.21
    // 读取两个相同的销售记录，并输出他们的和
    // Sales_data trans1, trans2;
    // std::cout << "请输入两条ISBN相同的销售记录：" << std::endl;
    // std::cin >> trans1 >> trans2;
    // if (compareIsbn(trans1, trans2))
    // {
    //     std::cout << "汇总信息：ISBN、销售本书、原始价格、实售价格、折扣为 "
    //               << trans1 + trans2 << std::endl;
    // }
    // else
    // {
    //     std::cout << "两条销售记录的ISBN不同" << std::endl;
    // }


    // P20 练习1.22
    // 读取多个具有相同ISBN的销售记录，并打印他们的和
    // Sales_data total, trans;
    // std::cout << "请输入几条ISBN相同的销售记录：" << std::endl;
    // if (std::cin >> total)
    // {
    //     while (std::cin >> trans)
    //     {
    //         if (compareIsbn(total, trans))
    //             total += trans;
    //         else
    //         {
    //             std::cout << "当前书籍的ISBN不同" << std::endl;
    //             break;
    //         }
    //     }
    //     std::cout << "有效汇总信息：ISBN、销售本书、原始价格、实售价格、折扣为 "
    //               << total << std::endl;
    // }
    // else
    // {
    //     std::cout << "没有数据" << std::endl;
    //     return -1;
    // }


    // P21 练习1.23
    // 读取多条销售记录，并统计每个ISBN各有几条记录
    // int num = 1;
    // Sales_data trans1, trans2;
    // std::cout << "请输入若干销售记录：" << std::endl;
    // if (std::cin >> trans1)
    // {
    //     while (std::cin >> trans2)
    //     {
    //         if (compareIsbn(trans1, trans2))
    //         {
    //             num++;
    //         }
    //         else
    //         {
    //             std::cout << trans1.isbn() << "共有 " << num << " 条销售记录" << std::endl;
    //             trans1 = trans2;
    //             num = 1;
    //         }
    //     }
    //     std::cout << trans1.isbn() << " 共有 " << num << " 条销售记录" << std::endl;
    // }
    // else
    // {
    //     std::cout << "没有数据" << std::endl;
    //     return -1;
    // }

    return 0;
}
