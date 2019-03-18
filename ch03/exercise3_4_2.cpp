#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 比较两个字符串长度是否相等
    // 如果不等，输出长度较大的那个
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        // string 的 size() 和 length() 方法完全一样，都是返回 string 对象的长度(去除\0后)
        // 一般而言，size() 用于返回容器的大小，length() 返回序列的长度
        // 对 string 而言，完全一样
        cout << "长度分别为:" << str1.size() << ", " << str2.size() << endl;
        if (str1.size() == str2.size())
        {
            cout << "长度相等" << endl;
        }
        else
        {
            // "?:"是三元运算符
            // 例如 string max = str1 > str2 ? str1 : str2
            // 表示如果 str1 > str2 为真，则 max = str1，否则 max = str2
            cout << "长度不等，长度较大的为："
                 << (str1.size() > str2.size() ? str1 : str2)
                 << endl;
        }
    }

    return 0;
}
