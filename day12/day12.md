 1. 函数的返回值的方式与变量初始化的方式一样，返回的值用于初始化调用点的一个临时量，这个临时量就是返回结果。比如返回值是一个`string`，那么即使返回的是一个形参的引用`string&`，那么它会被拷贝到调用点的临时量，然后返回。如果返回的是一个引用`string&`，则这个引用是所引对象的别名。
 2. 不要返回函数内局部变量的指针和引用。因为函数执行完毕后，它们会被销毁，导致引用或指向一个未定义的地址。需要判断，引用的是否是函数执行之前已经存在的对象。
 3. 如果函数返回值的定义是一个引用，则这个函数表达式是一个左值，可以执行`get_val() = 1`赋值操作（当然常量引用不能赋值），其他情况下都是右值。
 4. 列表初始化返回值，用于初始化表示函数返回的临时量。对于`vector<string>的返回类型`，可以直接`return {"xxx", "xxx"};`。
 5. 数组不能被拷贝，所以不能赋值给调用点临时量。凡是可以返回数组指针：
    1. 最原始的方法是：`int (*func(int i)) [10]`，表示函数的返回值可以被解引用(*)，解引用的结果是含有10个int的数组；
    2. 尾置返回类型：`auto func(int i) -> int(*)[10];`；
    3. 使用`decltype(arr)* func(int i)`。
6. 重载**只能**通过形参来区分，返回值是无法区分的。顶层const与非const的是无法区分重载类型的（`Phone* const p`和`Phone* p`）（`int`和`const int`）都是一样的重载类型。底层重载是可以区分的（`const Phone* p`和`Phone* p`），对于一个非const类型的参数，优先调用非const版本。`fn(nonConstPhone)`
7. 使用`const_cast`，定义重载：
    ```cpp
    // 底层const，可重载
    const string& shorterString(const string& s1, const string& s2)
    {
        // 返回值也是重载，并且在函数调用前已存在
        return s1.size() < s2.size() ? s1 : s2;
    }
    // 非const版本
    string& shorterString(string& s1, string& s2)
    {
        // 返回的是底层const，const string&，调用const版本；
        auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
        // 去掉底层const，返回一个string&
        return const_cast<string&>(r);
    }
    ```
8. 作用域内的函数声明，会覆盖作用域外的函数声明，导致只能找到作用域内的函数重载的声明。
