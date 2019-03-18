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
    // 一次读入一个词
    string word;
    // cin 是读到空格就停止，空格不会读进去
    // 且 cin 会忽略最开始的空格
    // >> 返回的cin本身
    while (cin >> word)
    {
        cout << word << endl;
    }
    return 0;
}
