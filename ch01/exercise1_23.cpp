#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currBook, book;
    std::cout << "Input sevaral same book sales recored: " << std::endl;
    if (std::cin >> currBook)
    {
        int cnt = 1;
        while (std::cin >> book)
        {
            // 此处也可以compareIsbn(currBook, book)
            if (currBook.isbn() == book.isbn())
            {
                ++cnt;
            }
            else
            {
                std::cout << currBook.isbn() << "\t" << cnt << std::endl;
                currBook = book;
                cnt = 1;
            }
        }
        std::cout << currBook.isbn() << "\t" << cnt << std::endl;
    }
    else
    {
        std::cout << "Input is empty, exit." << std::endl;
        return -1;
    }
    return 0;
}