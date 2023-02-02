1. 在算数运算中不要使用`char`和`bool`。因为`char`在不同的机器上有`signed char`和`unsigned char`两种形式。如果一定要使用，需要指明是否是有符号的。
2. 执行浮点运算优先选用`double`。`float`精度不够，而`float`和`double`运算代价基本相同。
3. 当给无符号类型一个超出它表示范围的值时，结果是值对于无符号数表示数值总数取模后的余数。
    ```cpp
    // (-1 + 2 ^ 8) % 256 = 255;
    unsigned char c = -1;
    ```
4. 当我们给带符号数一个超出范围的值时，结果是未定义(undefined)的。
    ```cpp
    // -256 ~ 255
    signed char c = (signed char)256;
    ```
5. 千万不要在表达式中，混用无符号数和有符号数。因为有符号数会先转成无符号数，并且运算的结果要确保是无符号的。
    ```cpp
    unsigned int u = 10, u2 = 11;
    int i = -42;
    std::cout << i + u << std::endl; // 4294967264
    std::cout << u + i << std::endl; // 4294967264
    std::cout << u - u2 << std::endl; // 4294967295 负数取模
    std::cout << u2 - u << std::endl; // 1
    ```
6. char是单引号，字符串字面量是双引号，本质是常量字符构成的数组，编译器在每一个字符串的结尾添加一个`\0`，因此字符串字面量的长度要+1。当两个字符串字面量仅由空格，缩进，换行符相隔，则它们实际上是一个整体。
7. 显示指定字面量的的类型，包括前缀和后缀：
    - 前缀u：`char16_t` Unicode16字符
    - 前缀U：`char32_t` Unicode32字符
    - 前缀L：`wchar_t` 宽字符
    - 前缀u8：UTF-8（仅作用在字符串字面量） char
    - 整形后缀u/U：unsigned 从`unsigned int` `unsigned long` `unsigned long long`中选择能容纳的最小类型；
    - 整形后缀l/L：至少是`long`；
    - 整形后缀ll/LL：`long long`或者`unsigned long long`；
    - 浮点后缀l/L：`long double`
    - 浮点后缀f/F：`float`
8. **列表初始化**，使用花括号`{}`对变量或对象进行初始化的操作。如果存在丢失信息的风险，则编辑器对列表初始化报错。
    ```cpp
    int i{0};
    int i(0);
    int i = 0;
    int i = {0};

    long double ld = 3.14;
    int i{ld}; // 报错
    int i(ld); // 通过
    ```
9. **分离式编译**，c++每个文件都是单独编译。一个文件内，如果想要用其他文件定义的名字，则必须包含这个名字的**声明**。
10. `extern`关键字，区分变量的声明和定义。变量可以被声明多次，但只能定义一次。如果在多个文件中使用同一个变量，则变量的声明和定义**必须**分离。变量的定义只能在一个文件中，而声明在用到变量的文件中都会出现。
    ```cpp
    extern int i; // 声明
    int i; // 声明并定义
    extern int i = 10; // 定义
    ```
11. `::`作用域操作符，可以使用`::i`访问全局作用域的变量。
