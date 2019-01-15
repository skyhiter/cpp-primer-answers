#include <iostream>

int main()
{
    int v = 0, sum = 0;
    // Unix按CTRL+D表示输入流终止（Win是CTRL+Z）
    // 正确的输入方式：1 2 3 4 5 回车 CTRL+D
    while (std::cin >> v)
    {
        sum += v;
    }
    std::cout << sum << std::endl;
    return 0;
}