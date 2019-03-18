#include <iostream>
#include <string>
using namespace std;
// 其实更推荐如下这种写法，这里为了省事，
// 一律使用using namespace std;代替
// using std::cin;
// using std::cout;
// using std::endl;
// using std::getline;

int main()
{
    // 一次读入一整行
    string line;
    // getline 可以读取开始和中间的空格，直到遇到换行符
    // 换行符也读进去了，但是后面又删掉了，即 line 里存的没有换行符
    // 如果一开始就是换行符，那么直接结束，line是空串
    while (getline(cin, line))
    {
        // line 本身无换行符
        cout << line << endl;
    }
    return 0;
}
