#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book1, book2;
    std::cout << "Input two same book sales recored: " << std::endl;
    std::cin >> book1 >> book2;
    // 或者使用compareIsbn(book1, book2)
    // if (compareIsbn(book1, book2))
    if (book1.isbn() == book2.isbn())
    {
        std::cout << "ISBN/Sales_vol/Sales/Avg_price is: "
                  << book1 + book2 << std::endl;
    }
    else
    {
        std::cout << "Different ISBN!" << std::endl;
    }
    return 0;
}