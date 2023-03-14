## 12.1
1. 静态内存，栈内存和堆内存。静态内存用于保存：
   1. 局部static对象；
   2. 类static数据成员；
   3. 定义在函数之外的变量。
2. `make_shared<T>`的指针用于初始化`T`对象，`p.get()`用于返回保存在智能指针对象中的真正的指针。当对`shared_ptr`进行拷贝和赋值时，每个`shared_ptr`都会记录有多少个其他`shared_ptr`指向相同的对象。拷贝发生在：
   1. 使用`shared_ptr`初始化另一个`shared_ptr`；
   2. 将`shared_ptr`作为参数，传递到函数中；
   3. 把一个`shared_ptr`作为函数的返回值。
3. 如果把`shared_ptr`放在一个容器中，记得不用时执行`erase`操作，触发容器内`shared_ptr`的销毁，检查引用计数，从而析构动态对象。
4. 使用动态内存的几个理由：
   1. 程序不知道需要使用多少个对象（容器类）；
   2. 程序不知道所需对象的准确类型；
   3. 程序需要在多个对象间共享内存；
5. `new`的几种初始化方法：
   1. 默认初始化：`int* p = new int;`（int后边没有括号，内置对象未定义，类对象调用默认构造函数）；
   2. 值初始化：`int* p = new int();`（int后边有括号，内置对象有定义）；
   3. 直接初始化：`int* p = new int(42);`或者`vector<int>* p = new vector<int>{1, 2, 3}`（括号内有值，或使用列表初始化）。
6. 可以使用`const`来修饰，得到一个指向常量的指针。`const string *p = new const string;`；
7. delete一直指针之后，指针的值就无效了，但是它依然指向了一块地址（地址内数据无效），成为“空悬指针”。
8. 可以使用`new`返回的指针来初始化`shared_ptr`，注意必须使用直接初始化的方式。
    ```cpp
    shared_ptr<int> p(new int(42));
    shared_ptr<int> p = new int(42); // error
    ```
    因为不能把一个内置指针，隐式的转换成一个`shared_ptr`，同理，一个返回`shared_pte`的函数也不能直接返回一个内置指针。
    ```cpp
    shared_ptr<int> clone(int p)
    {
        return new int(p); // error，想做int*到shared_ptr<int>的转换；
        return make_shared<int>(new int(p));
    }
    ```
9. `shared_ptr`的`reset`的用法：
   1.  `p.reset();`将p置空，如果是唯一一个指向对象的shared_ptr，还会释放对象；
   2.  `p.reset(q);`使p指向q；
   3.  `p.reset(q, d);`使用d来代替delete。
10. 不要混用`shared_ptr`和内置指针，如果使用`shared_ptr`接管内置指针，就不要在用内置指针操作对象了，因为对象可能会被`shared_ptr`释放；
11. 使用`shared_ptr`管理一些不是通过`new`创建的对象，通常来说，释放时也不需要执行`delete`（比如创建链接和断开链接）。可以自定义delete函数。
    ```cpp
    shared_ptr<connection> p(&connect, end_connection);
    ```
12. `unique_ptr`独享一个对象，并管理对象的销毁时机。所以不能对`unique_ptr`进行拷贝和赋值操作。但是可以使用`release`和`reset`转移对象的所有权。
    ```cpp
    unique_ptr<string> p2(p1.release()); // p1释放对于对象的所有权，p2接受
    p2.reset(p3.release()); // p3释放，p2接手
    ```
    注意`release`只是切断对象与`unique_ptr`的关系，并不会释放对象。
13. `unique_ptr`不能拷贝，但是作为函数的返回值时会进行特殊处理。
14. `weak_ptr`指向一个`shared_ptr`管理的对象，但是不会改变share_ptr的引用计数。

## 12.2
1. 通过`new int[]`得到的指向动态数组的指针，必须使用`delete[] p;`来删除，因为`p`就是一个指针，需要`[]`来告诉`delete`删除的是一个数组。
2. 可以使用`unique_ptr`来管理动态数组，使用`p.release();`会自动调用`delete[]`（TODO: 和非数组不一样？）。
    ```cpp
    unique_ptr<int[]> p(new int[10]());
    p[1] = 123;
    ```
3. `shared_ptr`不能直接管理动态数组，需要使用自定义的delete函数，同时，获取指向的数组中的元素的方式也需要定制。
    ```cpp
    // 自定义delete
    shared_ptr<int> sp(new int[10](), [](int* p) { delete[] p });
    for (size_t i = 0; i != 10; ++ i)
    {
        // 通过原始指针，获取指向的元素
        *(sp.get() + i) = i;
    }
    ```
4. 使用`new`和`delete`时，内存分配和对象构造必须在同时完成。但有时候需要先分配一大块内存，再按需构造对象。它的使用分为以下几个步骤：
   1. 生成`allocator`对象，指定元素类型；
   2. 分配allocate指定数量，指定类型个空间；
   3. 一个一个构建construct对象，或者copy/fill对象到已经allocate的空间；
   4. 析构destroy指定位置的对象；
   5. 释放deallocate申请的内存。
    ```cpp
    // 1. 创建allocator对象
    allocator<string> alloc;
    // 2. 分配n个空间，并返回初始指针p；
    auto const p = alloc.allocate(n);
    // 3. construct对象
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "hi");
    // 3. 或者copy/fill
    auto q = uninitialized_copy(vs.begin(), vs.end(), p);
    uninitialized_fill_n(q, 10, "hello");

    // 4. 执行销毁操作
    while (q != p)
    {
        alloc.destroy(--q);
    }

    // 释放申请的空间，p为allocate生成的首指针，n必须与allocate的一样
    alloc.deallocate(p, n);
    ```