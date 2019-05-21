## 中文第五版《C++ Primer》习题答案（Chinese 5th Edition Solutions）

经典著作《C++ Primer》中文第五版，示例代码基于 C++11 标准编写。中国工信出版集团 & 电子工业出版社，2013 年 9 月第 1 版，2018 年 6 月第 18 次印刷。

编译环境：

- Editor: [Visual Studio Code](https://code.visualstudio.com/)
- Platform: macOS Mojave 10.14.5(Darwin 18.6.0, x86_64), Intel i7-7920HQ@3.10GHz
- Compiler: Apple LLVM version 10.0.1 (clang-1001.0.46.4)
- Debugger: lldb-1001.0.13.3

编译命令：

- `g++ some_ex.cpp -o some_ex -std=c++11` (`clang`**必须**手动指定 C++11 的 flag)
- 这里的`g++`使用的`clang`前端，编译输出信息与`GNU g++/Visual Studio`相比可能有较大不同，还请大家注意

```
// g++(clang)版本
$ g++ --version (macOS的g++其实就是clang的别名，并不是真正的GUN g++)

Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk/usr/include/c++/4.2.1
Apple LLVM version 10.0.1 (clang-1001.0.46.4)
Target: x86_64-apple-darwin18.6.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

本项目大量参考:

- 第三方英文答案 [C++ Primer 5 answers](https://github.com/Mooophy/Cpp-Primer)
- 第三方中文答案[《C++ Primer》第五版中文版习题答案](https://github.com/huangmingchuan/Cpp_Primer_Answers)
- 官方答案书籍《C++ Primer 习题集》，第五版，电子工业出版社，2015 年 3 月第 1 版，2015 年 12 月第 4 次印刷

特别鸣谢 [huangmingchuan](https://github.com/huangmingchuan).

---

## 中文原书勘误

中文《C++ Primer》第五版（截止到 2018 年 6 月第 18 次印刷）包含了较多的错误，部分勘误如下：

### 1. `P16.` 练习 1.19

> 题目“修改你为 1.4.1 节练习`1.10`（第 11 页）...”改为“修改你为 1.4.1 节练习`1.11`（第 11 页）...”。

即 `1.10` 改为 `1.11`.

### 2. `P21.` 下方代码

> 1.6 书店程序，是不是有两行注释位置写反了？即第 5 行的注释 _"// 保存下一条交易记录的变量"_ 和第 8 行的注释 _"// 保存和的变量"_ 是不是应该**互相交换位置**？

Update: 已证实注释确实写反了，证据参见 P229 中间代码的注释：

```C++
// 证据：P229 代码节选

Sales_data total;       //保存当前求和结果的变量
if (read(cin, total)) { // 读入第一笔交易
    //编注：trans应该是transaction的缩写，表示交易、事务等
    Sales_data trans;   //保存下一条交易数据的变量

    ...

} else {
    ...
}
```

即 `P21.` 下方的示例代码中，第 5 行的注释 _"// 保存下一条交易记录的变量"_ 和第 8 行的注释 _"// 保存和的变量"_ 应该互相交换位置。

###
