#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total, book;
    std::cout << "Input sevaral same book sales recored: " << std::endl;
    if (std::cin >> total)
    {
        while (std::cin >> book)
        {
            // 此处也可以compareIsbn(total, book)
            if (total.isbn() == book.isbn())
            {
                total += book;
            }
            else
            {
                std::cout << "Different ISBN, exit." << std::endl;
                return -1;
            }
        }
        std::cout << "ISBN/Sales_vol/Sales/Avg_price is: "
                  << total << std::endl;
    }
    else
    {
        std::cout << "Input is empty, exit." << std::endl;
        return -1;
    }
    return 0;
}