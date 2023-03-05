## 10.1
1. 因为算法操作的是迭代器，因此，除了标准容器之外，还可以对内置数组进行算法操作，因为指针就像是内置数组的迭代器一样。
    ```cpp
    int ia[] = { 1, 2, 3 };
    int val = 2;
    // 返回值是迭代器（指针）
    int* result = std::find(std::begin(ia), std::end(ia), val);
    ```
2. 迭代器令算法不依赖于容器（某些程度上还是依赖容器能够实现的操作），但是算法依赖于元素类型的操作（比如元素类型是否支持`==`）。

## 10.2
1. 算法本身不会改变容器的大小，因此如果写入元素数量大于容器大小时。比如在一个空容器中给指定长度的值赋初值，这种行为是未定义的。
    ```cpp
    vector<int> vec;
    // 给vec的前十个元素赋值为0，时机上vec没有长度；
    fill_n(vec.begin(), 10, 0);
    ```
2. 使用插入迭代器（insert iterator），给插入迭代器复制时（`*iter = 42;`），会调用容器的插入方法，把被赋值的值插入到容器中。除此之外，把插入迭代器（迭代器的一种）作为参数传给容器长度不够的容器时，也会执行插入操作。
    ```cpp
    vector<int> vec;
    // 执行10次push_back
    fill_n(back_inserter(vec), 10, 0);
    ```
## 10.3
1. 谓词（predicate）就是作为参数传递给函数的可调用表达式。它可以本身就是一个函数，也可以是一个lambda表达式。
    ```cpp
    bool isShorter(const string& s1, const string& s1)
    {
        return s1.size() < s2.size();
    }
    // 一个函数，作为谓词，传递给算法sort
    sort(words.begin(), words.end(), isShorter);
    ```
2. 一个lambda表达式是一个可调用的代码单元，可以理解为一个未命名的，可以定义在函数内部的内联函数。它包含**[capture list](parameter list) -> return type {function body}**四部分。其中，参数列表和返回类型是可省略的。
3. lambda函数的参数不能有默认参数，所以**实参数目与形参数目一定相同**，可以值传递，也可以引用传递，与普通函数相同。
4. 捕获列表捕获的是**所在函数中定义的非static局部变量的列表**。
5. 当定义lambda表达式时，编辑器生成一个与lambda对应的，新的类类型，当向一个函数传递lambda表达式时，就是传递了一个该类型的对象。当使用`auto`定义一个用lambda初始化的变量时，就是定义了一个类的对象。捕获的变量就是lambda对象的数据成员，在创建时被初始化。
    ```cpp
    void fn()
    {
        size_t v1 = 42;
        auto f = [v1] { return v1; }; // 对象创建，数据成员被初始化；
        v1 = 0;
        auto j = f(); // 42，lambda对象在定义时，成员函数已经被复制为42
    }
    ```
6. 捕获可以使用引用，但是要确保被引用的对象，在lambda执行时是存在的（可被引用到）。如果lambda可能在函数执行结束后执行，则引用捕获指向的局部变量就已经消失了。但是有的对象，比如io对象，是不可拷贝的，必须是引用捕获。
7. 可以使用隐式捕获，来自动分析需要捕获哪些值`[=]`，`[&]`，`[&, c]`（除c之外其他都是引用捕获）。
8. 值捕获，lambda本身是不能修改他的值（类类型对象中的数据成员，在lambda内部不能改变）。如果希望改变（数据成员），需要指定`mutable`。
    ```cpp
    void fn()
    {
        size_t v1 = 42;
        auto f = [v1] () mutable { return ++ v1; };
        v1 = 0;
        auto j = f(); // 43 改变了类类型成员的值，同时因为是拷贝，所以外部的修改不会影响内部的数据成员
    }
    ```
9. 如果lambda函数体中，有除了`return`之外的其他语句，则必须指定返回类型，否则被认为是`void`从而导致编译错误。
10. 使用`bind`函数，把可执行对象，包裹成带有参数的另一个可执行对象。`auto newCallable = bind(callable, arg_list);`，类似于js的bind方法。但是，需要指定newCallable参数的顺序，哪些来自`newCallable`调用，哪些来自`arg_list`。
    ```cpp
    // _1来自`std::placeholders::_1`，表示`check_size`的第一个参数，来自生成的newCallable的第一个参数，
    // `check_size`第二个参数`sz`，直接传入到`newCallable`
    auto wc = find_if(w.begin(), w.end(), bind(check_size, _1, sz));
    ```

## 10.4
1. 插入迭代器绑定在一个容器上，给插入迭代器赋值就是调用容器的插入方法，给容器塞值；分为`back_inserter`，`front_inserter`和`inserter`。注意必须要在支持`push_back`或者`push_front`的容器上，才能生成插入迭代器。注意`interser`，如果传递给inserter的位置原来指向第一个元素，只要在此元素之前插入一个新元素（`inserter`会在指向位置之前插入元素），则这个元素就不再是容器的首元素了。
    ```cpp
    // l.begin()，第一次插入指向l的第一个元素，后来就不再指向了。
    copy(v.begin(), v.end(), inserter(l, l.begin()));
    ```
2. `istream_iterator`（读取输入流，实现了`>>`的对象），`ostream_iterator`（想输出流写数据，手事项了`<<`的对象）。可以使用流迭代器，用泛型算法从流读取或向流写入数据。
    ```cpp
    istream_iterator<int> in(cin), eof; // eof:流的尾后迭代器，用于判断（in == eof），in: 被绑定在`cin`上。
    vector<int> iv(in, eof); // 把cin输入流的信息读入到iv中

    ostream_iterator<int> out(cout, " "); // 把out绑定到cout上，每次给out赋值，就是往cout中输出值，并且后边加一个空格。
    out = 123;
    copy(iv.begin(), iv.end(), out); // 把iv中信息输入到cout中，并且每一个值后都有一个空格
    ```
3. 反向迭代器，通过`vec.rbegin()`和`vec.rend()`生成，对迭代器`++`，向后移动。（不能是`forward_list`或者`流对象`）。通过反向迭代器生成的迭代器，也是反向的，可以通过`iter.base()`得到相应的正向迭代器，但是反向迭代器和它相应的正向迭代器，由于左开右闭和左闭右开的原则，指向的不是同一个元素。反向迭代器在反向迭代器的`base`迭代器之前一个位置。

## 10.5
1. 迭代器是通过它们能够执行的操作类进行分类的（指向的容器支持的迭代器操作）。有5种类型：
   1. 输入迭代器：比较（`==`或`!=`），递增（`++`），读取（右侧解引用`*iter`）。因为支持递增，所以必须是顺序的，执行单遍扫描；
   2. 输出迭代器：递增，左侧解引用，单遍扫描；
   3. 前向迭代器：读写元素，一个方向移动，多遍扫描，`forward_list`上的迭代器就是前向迭代器；
   4. 双向迭代器：读写，支持递增`++`和递减`--`，除了`forward_list`，其他容器都支持；
   5. 随机访问迭代器：在常量时间内访问序列中的任意元素，`array`，`deque`，`string`和`vector`等顺序容器都是这种。
2. 算法命名规范：
   1. 重载：通过传入不同的参数重载，比如`unique(beg, end);`和`unique(beg, end, comp);`；
   2. `_if`：传入谓词版本，`find(beg, end, val)`和`find_if(beg, end, comp);`；
   3. `_copy`：拷贝版本，`reverse(beg, end);`和`reverse_copy(beg, end, dest);`；
   4. `_copy_if`：组合拷贝和谓词。`reverse(beg, end, back_inserter(v2), []() {};`。

## 10.6 
1. 链表容器有它特定的算法（`sort`，`merge`，`remove`，`reverse`），因为与顺序容器的不同，链表算法的效率更高，通过成员函数调用。
2. splice算法，`lst(p, lst2);`，`lst(p, lst2, p2)`和`lst(p, lst2, b, e)`。
3. 链表版本与通用版本一个重要区别是：链表版本会改变底层的容器。比如`remove`版本会直接删除链表内的指定元素，`unique`会删除第二个和后继相同的元素（非链表版本返回一个指向移动后的第一个重复元素的迭代器，需要自己erase），`merge`和`splice`会销毁参数中的链表。（因为是成员函数的原因吧…）
