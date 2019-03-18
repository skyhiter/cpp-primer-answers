#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    string word, line;
    cout << "请选择读取字符串的方式：1 表示逐词读取，2 表示整行读取" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
    {
        cout << "请输入字符串(前后各4空格)：    Welcome to C++ family!    " << endl;
        cin >> word;
        cout << "系统读取的有效字符串是：" << endl;
        cout << word << endl;
        return 0;
    }
    // 清空 cin 的各种状态
    cin.clear();
    // 注意，一些人可能会写 cin.sync(); 这是个错误用法，应该用ignore()
    // 清空 cin 缓冲区
    // istream& ignore (streamsize n = 1, int delim = EOF)
    // numeric_limits 需要 #inlcude <limits>
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (choice == '2')
    {
        cout << "请输入字符串(前后各4空格)：    Welcome to C++ family!    " << endl;
        getline(cin, line);
        cout << "系统读取的有效字符串是：" << endl;
        cout << line << endl;
        return 0;
    }
    cout << "您的输入有误!" << endl;
    return -1;
}
