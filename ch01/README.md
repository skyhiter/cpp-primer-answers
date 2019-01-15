## 练习1.1

> 查阅你使用的编译器文档，确定它所使用的文件命名约定。编译并运行第2页的main程序。

### 1. 常见的C++文件扩展名
- 源文件：`.cpp`, `.cc`, `.cxx`, `.C`, `.c++`
- 头文件：`.h`, `.hpp`, `.hxx`

**Unix平台多为`.cc`，其他平台多为`.cpp`，头文件推荐使用`.h`或`.hpp`。**

参考链接:
 - [C++源文件的后缀名问题](https://www.cnblogs.com/bluestorm/archive/2012/09/05/2672527.html)
 - [*.h or *.hpp for your class definitions](https://stackoverflow.com/questions/152555/h-or-hpp-for-your-class-definitions)
 - [C++ code file extension? .cc vs .cpp](https://stackoverflow.com/questions/1545080/c-code-file-extension-cc-vs-cpp)
 - [.c vs .cc vs. .cpp vs .hpp vs .h vs .cxx [duplicate]](https://stackoverflow.com/questions/5171502/c-vs-cc-vs-cpp-vs-hpp-vs-h-vs-cxx)

### 2. 编译命令
对于GUN编译器套件来说，编译C++源文件需要在终端输入`g++ -o test test.cpp -Wall`,其中`-o test`指的编译生成的可执行文件是`test`,没有`-o`则默认是`a.out`; **`-Wall`是开启所有warning的意思，强烈推荐加上这个flag**。

要运行刚才生成的`test`需要在终端输入`./test`，要注意的是这里需要手动指定`test`的路径，即使在当前目录下，妄图输入`test`运行是不行的（因为直接输入`test`的话会在系统环境变量试图查找命令`test`）。

## 练习1.2

> 改写程序，让它返回-1。返回值-1通常被当作程序错误的标识。重新编译并运行你的程序，观察你的系统如何处理main返回的错误标识。

`exercise1_2.cpp`文件内容如下：
```C++
#include <iostream>

int main()
{
    return -1;
}
```
终端执行`g++ -o exercise1_2 exercise1_2.cpp -Wall`,然后`./exercise1_2`, 再`echo $?`，发现输出为`255`.
```
$ g++ -o exercise1_2 exercise1_2.cpp -Wall
$ ./exercise1_2
# Unix系统命令 echo $? 记录上一个程序的返回值（windows为echo %ERRORLEVEL%，输出-1）
$ echo $?
# 这里本来应该是-1的，但是Unix的程序exit code定义为8-bits的unsigned int, -1转8-bits unsigned int就是255
255
```
![excercise1_2_command](../pictures/exercise1_2_command.png)