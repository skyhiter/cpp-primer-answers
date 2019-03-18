#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 将多个字符串拼接一起输出，用空格隔开
    string result, str;
    // 先读第一个，原因是后面需要加空格，
    // 但是整个拼接的结果最前面不能有空格
    cin >> result;
    // 开始读第二个，第三个...
    while (cin >> str)
    {
        result += " " + str;
    }
    cout << result << endl;

    return 0;
}

/*
// 也可以这么做
int main()
{
    // 将多个字符串拼接一起输出，用空格隔开
    string result, str;
    while (cin >> str)
    {
        // 第一个前面不能加空格，所以这里需要判断一下
        if (!result.size())
        {
            result = str;
        }
        else
        {
            // 除了第一个外，其他的前面都要加空格
            // result =  result + " " + str;
            result += " " + str;
        }
    }
    cout << result << endl;

    return 0;
}
*/