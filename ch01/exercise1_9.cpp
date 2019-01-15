#include <iostream>

int main()
{
    int sum = 0, start = 50;
    while (start <= 100)
    {
        sum += start;
        ++start;
    }
    std::cout << "sum is " << sum << std::endl;
    return 0;
}