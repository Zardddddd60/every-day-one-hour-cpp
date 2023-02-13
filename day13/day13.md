1. 局部变量不能作为默认实参，在函数之外定义的函数，变量都能作为默认实参。用作默认实参的名字在函数声明所在的作用域内解析，求值过程发生在函数调用时。
   ```cpp
   sz wd = 80;
   char def = '';
   sz ht();
   string screen(sz = ht(), sz = wd, char = def);

    void f2()
    {
        def = '*'; // 修改了全局变量def，影响screen调用时的参数值；
        sz wd = 100; // 未影响同名全局变量，不影响screent调用的默认参数值；
        window = screen(); // ht(), 80, '*'
    }
   ```
2. 函数的调用一般比等价操作开销大。编译器可以把内联函数在每个调用点“内联地”展开（相当于把函数体拷贝过去）。可以用于优化规模小，流程直接，调用频繁的函数。
3. `constexpr`函数返回的结果直接编译器进行替换（类似内联），`constexpr`函数必须遵循：
   1. 参数必须是常量表达式，不能是变量；
   2. 函数体重只能有一个return；(c++14有extension可以返回多个)
4. 内联函数和`constexpr`函数定义在头文件中，保证定义完全一致，供编译器替换。
5. `assert`是一个预处理宏，本质是一个**预处理变量**，行为类似内联函数。`assert`宏定义在`cassert`中，预处理名字**由预处理器，而非编译器管理**，所以不用加`std::assert`，宏名字在程序内必须唯一，所以不要定义`assert`名字的函数。
6. `NDEBUG`预处理变量。如果定义了`#define NDEBUG`，则`assert`不生效。可以用一些编译器定义的局部静态变量，帮助调试：
   1. `__function__`：调试函数的名字；
   2. `__FILE__`：文件名；
   3. `__LINE__`：当前行号；
   4. `__TIME__`：编译时间；
   5. `__DATE__`：编译日期。
7. 函数指针指向函数，函数的类型由返回值和形参列表组成，所以定义函数指针时要指明这两个值，与函数名无关。
    ```cpp
    // 一个指针，指向函数，函数返回值bool，形参为(const string&, const string&)
    bool (*pf) (const string&, const string&); 
    ```
    与数组一样，函数名大部分情况下被编译器解释成函数的指针。
    ```cpp
    bool lengthCompare(const string&, const string&);
    // lengthCompare被当做指针
    pf = lengthCompare;
    ```
    可以直接使用指针调用函数，也可以解引用后调用。
    ```cpp
    pf("a", "b");
    (*pf)("a", "b");
    ```
    指向不同函数类型的指针不能转换，但是可以用0表示不指向任何函数。
    ```cpp
    pf = 0;
    ```
    重载时，指针类型必须与函数类型精确匹配。
    ```cpp
    void ff(int*);
    void ff(unsigned int);
    void (*pf) (unsigned int) = ff;
    void (*pf2) (int) = ff; // 报错，精确匹配
    ```
    与数组一样，`decltype`返回的是函数本身，而不是函数指针，所以
    ```cpp
    typedef bool Func(const string&, const string&) // 函数
    typedef decltype(lengthCompare) Func2; // Func2 是函数
    using F = int(int*, int); // 函数

    typedef bool (*FuncP) (const string&, const string&); // 函数指针
    typedef decltype(lengthCompare) *Func2; // 函数指针
    using FP = int(*)(int*, int); // 指针
    ```