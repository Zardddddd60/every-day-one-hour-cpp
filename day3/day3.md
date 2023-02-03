1. 应用为对象起了另一个名字，引用类型引用(refer to)另外一种类型。一般初始化变量时，初始值会被**拷贝**到新对象中。定义引用时，只是把引用和初始值**绑定**。引用即别名。
    > 引用并非对象，它只是为一个已经存在的对象起的另一个名字。
2. 指针是指向(point to)另一种类型的符合类型，也实现了对其他对象的间接访问。它与引用的不同在于：
   1. 指针本身是对象，允许对指针的拷贝和赋值；
   2. 指针不需要在定义时赋初值。
3. 指针不是对象，没有地址，所以不能定义指向引用的指针。
4. `nullptr`是一种特殊类型的字面值，用于生成空指针。它**可以被转成任意其他类型的指针**。建议初始化所有指针，如果不知道指向哪里，使用`nullptr`或者`0`。
    ```cpp
    int* p = nullptr; // c++11引入的最新方式
    int* p = 0;
    int* p = NULL; // #include <cstdlib>，是一个预处理变量，尽量避免使用
    ```
5. 任何非0指针对应的条件都是true。
    ```cpp
    int ival = 1024;
    int* p1 = 0;
    int* p2 = &ival;
    if (p1) // 不通过
    if (p2) // 通过
    ```
6. `void*`是一种特殊的指针类型，可用于存放**任意类型对象的地址**。因为不着调`void*`指向对象的类型，所以无法确定能做哪些操作。只能拿它和别的指针比较，或者作为函数的输入/输出。以`void*`的视角看，内存空间就是内存空间，不能访问空间的对象。
7. 指针本身是一个对象，所以可以用引用来引用它。可以**从右到左**解释`int* &r = p`。先遇到`&`，所以它是一个引用（对变量的类型有最直接的影响），其余部分用来指定引用的是什么，也就是引用了`int*`，一个整形指针。
8. 因为`const`对象创建后，值就不能改变，所以`const`对象必须初始化。对象的常量特性只在执行改变对象的操作时才会生效。
    ```cpp
    const int i = get_size(); // 运行时初始化
    const int j = 42; // 编译时初始化
    ```
9. 默认情况下，`const`只对本文件有效。**如果多个文件定义了同名的const变量，等同于在不同文件中分别定义了独立变量**。如果想在多个文件共享同一个const变量，使用`extern`声明和定义const变量。指明声明的const变量不是文件独有，定义在别处。
10. `const引用`（对于const的引用）。
    1.  对常量的引用，不能用来改变引用量的值。
        ```cpp
        const int i = 0;
        const int& j = i;
        j = 1; // 报错
        int& k = j; // 报错。普通引用不能引用对于const的引用。
        ```
    2.  const引用可以引用一个常量。
        ```cpp
        const int& i = 42; // 正确
        int& j = i * 2; // 报错，int引用不能引用常量
        ```
    3.  常量引用引用不同类型的值时，先生成一个经过转换的**临时量对象**，然后把这个临时量对象绑定给这个引用。
        ```cpp
        double d = 1.23;
        const int& i = d; // 通过

        // 相当于
        const int temp = d;
        const int& i = temp;
        ```
        > 临时量对象，编译器使用一个空间来暂存求值结果时，临时创建的一个未命名对象。
    4. 可以使用const引用去引用一个非const变量或非const引用，只是不能通过这个const引用改变值。
        ```cpp
        int i = 42;
        int& j = i;
        const int& k = i; // 通过
        j = 43; // 通过
        k = 44; // 失败
        ```