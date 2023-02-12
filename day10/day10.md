1. 寻找处理异常的代码（catch）的过程与函数调用链正好相反。先搜索抛出异常的函数，寻找匹配的catch（和抛出的异常的类型是一样的）。如果没有，终止这个函数的执行，去找调用这个函数的函数。
2. 使用`stdexcept`的`runtime_error`生成一个异常对象。`throw runtime_error('xxxx')`
    ```cpp
    try
    {
        throw std::length_error("some thing error....");
    }
    catch (std::runtime_error e)
    {
        std::cout << "runtime error: " << e.what() << std::endl;
    }
    catch (std::length_error e)
    {
        std::cout << "length error: " << e.what() << std::endl; // length error: some thing error....
    }
    ```
3. `stdexcept`定义了几种很常用的异常对象，还能从`exception`的`exception`（默认初始化，值抛出异常，不说明原因），`new`的`bad_alloc`（默认初始化）和`type_info`的`bad_cast`（默认初始化）。