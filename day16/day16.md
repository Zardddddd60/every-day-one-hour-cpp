1. 初始化和赋值是有区别的。如果构造函数初始化列表没有**显示地**初始化成员，则这个成员在构造函数体之前**会执行默认初始化**。当类成员是`const`或者`引用`时，**必须**使用构造函数初始化列表初始化这些成员。因为他们不能执行赋值操作。类似的，类成员是一个没有提供默认构造函数的类型时，也**必须**初始化。
2. 构造函数初始化列表的定义顺序不是真正的初始化顺序，是与类定义的成员顺序。最好让**构造函数初始值的顺序与成员声明的顺序保持一致**。
3. 如果一个构造函数提供默认实参，使得不需要传递实参也可以初始化类对象时，则这个函数可以当作默认构造函数。
4. 委托构造函数，执行某种函数重载时，在**构造函数初始化列表**的地方通过类名+参数列表委托给指定的构造函数。它的执行过程为：
   1. 被委托函数的构造函数初始化列表；
   2. 被委托函数的构造函数体；
   3. 委托函数自己的构造函数体。
    ```cpp
    class Sales_data
    {
        public:
            Sales_data(std::string s): bookNo(s) {}
            Sales_data(): Sales_data("") {} // 委托给第一个构造函数
    }
    ```
5. 当构造函数只有一个实参时，则定义了类类型的隐式转换规则。隐式转换只能转换一次。转换的过程是创建一个临时量，使用临时量，最后丢弃。
    ```cpp
    // 本身combine接受一个Sales_data，但是通过隐式转换，通过string调用Sales_data只有一个实参的构造函数。
    item.combine(std::stirng("999"));
    ```
6. 如果要禁止这种隐式转换，使用`explict`在类内构造函数声明时指定。同时，使用`explict`修饰的构造函数**只能用于直接初始化，而不能拷贝形式的初始化**。
    ```cpp
    Sales_data item(std::stirng("999")); // ok 直接初始化
    Sales_data item = std::string("999"); // error 拷贝初始化
    ```
7. 聚合类的条件：
   1. 所有成员public；
   2. 无任何构造函数；
   3. 没有类内初始值；
   4. 没有基类和virtual。
    一个比较简单的聚合类就是`struct`，它可以通过花括号括起来的初始值列表，初始化聚合类的数据成员。
    ```cpp
    struct Data
    {
        int ival;
        string s;
    };

    Data d = { 0, "val" };
    ```
    初始值顺序**必须**与声明顺序一致。当初始值个数小于成员数时，后边的进行值初始化。初始值个数不能大于成员数。
8. 字面值常量类，条件：
   1. 数据成员必须是字面值类型；
   2. 类至少一个constexpr构造函数；
   3. 数据成员有类内初始值，则内置类型成员的初始值必须是常量表达式，类类型成员初始化值必须使用类成员自己的constexpr构造函数；
   4. 必须使用析构函数的默认定义。
    字面值常量类的`constexpr`构造函数必须初始化所有数据成员，函数体内不能有任何语句（满足构造函数无return和constexpr只有一个return的要求）。