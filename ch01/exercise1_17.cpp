#include <iostream>

int main()
{
    // currVal是我们正在统计的数，val是当前新读入的数
    int currVal = 0, val = 0;
    // Unix按CTRL+D表示输入流终止（Win是CTRL+Z）
    // 正确的输入方式：1 2 3 4 5 回车 CTRL+D
    // currVal可以理解为第一个数吧
    if (std::cin >> currVal)
    {
        int cnt = 1; // 记录当前数的个数，需要从1开始，因为已经读了一个
        while (std::cin >> val)
        {
            if (val == currVal)
            {
                ++cnt;
            }
            else // 遇到了新的一个数，需要打印当前的数，然后再重新计数
            {
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        // 打印最后一个值的个数
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
    }
    return 0;
}