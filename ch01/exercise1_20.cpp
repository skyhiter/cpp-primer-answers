#include <iostream>
#include "Sales_item.h"

/*
精简版本
using std::cin;
using std::cout;
using std::endl;

int main()
{
	for (Sales_item item; cin >> item; cout << item << endl);
	return 0;
}
*/

int main()
{
    Sales_item book;
    std::cout << "Input book sales recored: " << std::endl;
    while (std::cin >> book)
    {
        std::cout << "ISBN/Sales_vol/Sales/Avg_price is: "
                  << book << std::endl;
    }
    return 0;
}