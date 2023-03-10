1. 类的成员函数有一个隐形参数`this`，它本身的类型是一个`ClassName* const`，即本身是一个常量，指向调用对象，不允许修改指向的指针。可以看到，当对象是一个常量时，this是无法指向这个常量的。当在成员函数的参数列表之后加`const`，它把指针改变为一个指向常量的指针`const ClassName* const`，可以访问常量对象了。同时也无法在函数内修改对象的成员变量。
2. 定义成员函数的返回类型为`ClassName&`，同时返回时`return *this;`，可以把这个对象，作为左值返回回去。
3. 如果类中没有声明任何构造函数，则编译器会生成一个**合成的默认构造函数**。如果定义了类内初始值，则用类内初始值初始化成员，否则内置类型和复合类型（指针/数组）呗定义为未定义。尽量自定义不带任何参数的默认构造函数，因为：
    1. 编译器只有在发现没有任何构造函数时才会创建合成的默认构造函数；
    2. 内置类型和复合类型是未定义的；
    3. 成员中包含其他类类型的成员，而这个类没有默认构造函数，编译器无法初始化该成员，此时必须自定义构造函数。
4. 当我们定义了构造函数，但是想保留编译器提供的合成默认构造函数，可以使用` = default`。
    ```cpp
    Sales_data() = default;
    ```
5. 构造函数初始化列表，负责为对象中的数据成员赋初值。没有构造函数初始化列表的构造函数，可以看成是构造函数初始化列表为空的构造函数。
6. 对象的拷贝发生在初始化，值传递或值返回时；赋值发生在赋值运算符中。默认情况下，编译器会生成对每一个成员执行拷贝，赋值，销毁的相应函数。但是当存在**分配类对象之外的资源时**，编译器生成的版本会失效。
7. 友元在类中的声明仅仅是指定了访问权限，在类的外部依然需要友元函数的声明。通常来说把友元声明和类本身放在同一个头文件里。