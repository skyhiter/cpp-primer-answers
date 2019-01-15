#include <iostream>

int main()
{
    std::cout << "/*";
    std::cout << "*/";
    // std::cout << /* "*/ " */;
    std::cout << /* "*/ " /* " /*" */;

    std::cout << std::endl << "finished!" << std::endl;
    return 0;
}