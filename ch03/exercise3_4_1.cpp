#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 比较两个字符串是否相等
    // 如果不等，输出较大的那个
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        if (str1 == str2)
        {
            cout << "字符串相等" << endl;
        }
        else
        {
            // "?:"是三元运算符
            // 例如 string max = str1 > str2 ? str1 : str2
            // 表示如果 str1 > str2 为真，则 max = str1，否则 max = str2
            cout << "字符串不等，较大的为：" << (str1 > str2 ? str1 : str2) << endl;
        }
    }

    return 0;
}
