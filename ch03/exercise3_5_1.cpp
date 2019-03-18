#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 将多个字符串拼接一起输出
    string result, str;
    while (cin >> str)
    {
        result += str;
    }
    cout << result << endl;

    return 0;
}
