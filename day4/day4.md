1. 指向常量的指针(pointer to const)，可以指向常量，也可以指向非常量。但是不能通过指针修改指向对象的值。
    ```cpp
    const double pi = 3.14;
    double* ptr = &pi; // 报错，普通指针不能指向常量，否则可以通过指针修改常量
    const double* cptr = &pi; // 从右往左解读，首先是一个指针，指向一个双精度常量
    ```
2. 指针是对象，所以自己本身可能是一个常量。常量指针(const pointer)指向的地址不能变，因此必须初始化时赋值。
    ```cpp
    int* const curErr = &err; // 从右往左解读，本身是常量对象，类型是int指针
    *curErr = 2; // 通过，指针是常量，指向的对象不是，可以通过常量指针修改
    const double* const pip = &pi; // 本身是常量，指向双精度常量
    ```
3. 顶层const和底层const。值本身是一个const，称为顶层const，比如`const int ci = 0;`或者`int* const p = &q;`，而引用或者指向的值为const，称为底层const。比如，`const int& ir = i;`或者`const int *ip = &i;`。它们之间的是否能相互赋值，取决于能否通过新的指针/引用去改变一个对象，如果对象本身是const，那么引用/指针不能去改变这个对象。
4. 常量表达式(const expression)，有两个要求：
   1. 常量，用const定义；
   2. 在编译时就能得到计算结果。
    
    ```cpp
    const int max_files = 20; // 常量表达式
    const int limit = max_files + 1; // 常量表达式
    int staff_size = 27; // 不是
    const int sz = get_size(); // 不能在编译时得到结果
    ```
    可以使用`constexpr`类型来声明变量，使得编译器来验证变量的值是否是一个常量表达式。函数可以用`constexpr`来修饰，因此也可以用`constexpr`函数来初始化一个`constexpr`变量。
    ```cpp
    constexpr int mf = 20;
    constexpr int limit = mf + 1;
    constexpr int sz = get_size(); // constexpr函数
    ```
    > 一般来说，如果认定一个变量时常量表达式，就把它声明成constexpr类型。
5. 一个`constexpr的指针`，必须指向地址固定的对象。函数体内的定义的变量位置不固定，因此不能用`constexpr`指针指向函数体内的对象。注意`constexpr指针`限制的是顶层指针，即指针指向的地址不能变。
    ```cpp
    constexpr int ci = 1;
    int i = 2;
    int main()
    {
        int i2 = 3;
        constexpr int* cip = &i; // 正确，顶层const可以引用非const值；
        constexpr int* cip2 = &i2; // 错误，必须是函数外的值
    }
    ```
6. 定义类型别名的方法：
   1. `typedef double wages, *p;`使用`typedef`定义wages为double，定义p为double*；
   2. `using SI = Sales_Item;`

    注意，`const p = 0`，并代表`const double* p = 0`，它是一个常量指针，即`double* const p = 0`
7. 使用`auto`进行类型推导时，会去掉本身的引用和`顶层const`属性。可以通过手动添加的方式把顶层const和引用加回来。

    ```cpp
    int i = 0;
    int& j = i;
    auto k = j; // 删掉引用，k为int；

    const int i = 0;
    const int& j = i;
    auto k = i; // k为int，顶层const被删掉；
    auto k2 = j; // k2为int，顶层const和引用被删掉
    auto k3 = &i; // k3为（底层）const int*，指向常量的引用

    // 恢复顶层const
    const auto k4 = i; // 手动给auto得到的类型，添加const，变成const int类型
    // 恢复引用
    auto& k5 = i; // 手动添加引用，变为int&
    ```
8. 要在一条语句中定义多个变量，`*`和`&`**只属于某个声明符，而不是基本数据类型的一部分**。
    ```cpp
    auto &m = i, *p = &i; // m是整形引用，p是指向整形的指针
    ```
9. `decltype`类型只是符。从表达式的类型，推断出要定义的变量，但不想用这个表达式的值初始化（auto）。
    ```cpp
    // 使用函数f的返回类型定义sum的类型
    decltype(f()) sum = x;
    ```
    它与`auto`不同之处在与推导**变量类型**的顶层const和引用时，不会删掉这些类型信息。
    ```cpp
    const int ci = 0, &cj = ci;
    decltype(ci) x = 0; // x 是 const int
    decltype(cj) y = x; // y 是 const int&，常量引用，必须初始化
    ```
10. `decltype`使用的表达式不是变量，则返回表达式对应的类型。
    ```cpp
    int i = 0, &ir = i;
    decltype(ir + 0) j; // 正确，j是int
    ```
    如果表达式是指针解引用，则结果是一个**引用类型**。
    ```cpp
    int *p = &i;
    decltype(*p) r; // 报错，引用r必须初始化
    ```
    注意，变量放在括号内会被认为是表达式，返回的一定是引用。
    ```cpp
    decltype((i)) r2; // 报错，引用r2要初始化；
    decltype(i) r3; // 不报错，r3是int类型
    ```
11. **头文件通常包含那些只能被定义一次的实体**，比如类，`const`或者`constexpr`。为了确保头文件被多次包含，依然能正常工作，需要使用**预处理器(preprocessor)**，它实在**编译之前执行的一段程序**，可以改变我们所写的程序。`#include`就是一个预处理器功能。头文件保护符`#ifndef`也是预处理器。配合`#define`和`#endif`一起使用。