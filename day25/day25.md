## 11.1

## 11.2
1. 对于有序容器`map`，`set`，`multimap`，`multiset`，key值必须定义比较方法，默认使用key的`<`运算符。初次之外也可以在初始化时传递一个比较函数（指向函数的指针）用作排序。
    ```cpp
    bool compareIsbn(const Sales_data& l, const Sales_data& r)
    {
        return -1;
    }
    // 定义类型decltype(compareIsbn)*，一个函数指针。并传入比较函数（是一个指针形式，&compareIsbn）
    // bool (*) (const Sales_data&, const Sales_data&)
    multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
    ```
2. `pair`是一个用于生成类型的模版。`pair`类型有两个公有数据成员`first`和`second`，可以通过`make_pair(v1, v2)`生成，也可以使用列表初始化（`{v1, v2}`）。

## 11.3
1. 关联容器定义了`key_type`，`value_type`，`mapped_type`。`set`中`key_type`和`value_type`相同。
2. `map`的`value_type`是`pair<const K, V>`，`pair->first`自动被转成`const`。使用迭代器时，返回的是`value_type`。无法通过`iter->first`来修改key值，因为它是`const`的。
3. 即使关联容器也有迭代器，但基本不会对它直接使用算法，而是把关联容器作为算法的输入范围或者输出范围。注意关联容器没有实现`back_push`，所以不能使用`back_inserter`对关联容器进行插入操作，可使用`inserter`。
4. `insert`方法的返回值依赖容器类型和参数类型。当给非multi容器插入单个元素时，`insert`和`emplace`返回一个`pair`，`p.first`是一个迭代器，指向指定key的元素，`p.second`是一个布尔值，表示是否真的进行插入操作。对于`multi`容器插入单个元素，总是返回执行元素的迭代器。
5. 关联容器可以使用`erase`成员函数，对于参数类型为迭代器范围或者单一迭代器的`erase`，返回void。如果`erase`的参数是一个`key_type`，则返回值时一个整数，表示真正删除的元素的个数。
6. 可以对非multi的map执行下标操作或者`at(key)`。注意，如果关键字不在`map`内，则下标操作会创建一个map中的元素，进行值初始化。因为可能对map进行修改，所以只能对非`const`得map执行下标操作。执行下标操作，返回的是一个`mapped_type`（解引用迭代器返回的是`value_type`）。
7. 使用`find`返回指向第一个具有key的元素迭代器+`count`返回具有相同key的元素的数量，加上有序的（非unordered）顺序存储（++iter），来遍历所有具有相同key的元素。也可以使用`lower_bound`和`upper_bound`相同的关键字，得到一个左闭右开的范围。还可以使用`equal__range`，返回一个迭代器`pair`，分别指向满足key的第一个元素和最后一个元素之后的位置。

## 11.4
1. 无序容器使用**桶**来组织储存，每个桶有0个或多个元素。通过一个哈希函数，把key分到不同的桶，桶内元素是顺序存储的，因此，无序容器有一些对桶进行调整的成员函数。
2. 无序容器需要一个key具有哈希函数（`hash<key_type>`类型的对象）和`==`操作符。标准库为内置类型，string和智能指针都提供了hash模版，所以这些类型做key时，不需要显示的提供哈希函数和`==`。对于自定义类型，在初始化时，可以通过hash函数和`==`（如果自定义类类型没有实现`==`操作符时）。
    ```cpp
    size_t hasher(const Sales_data& sd)
    {
        return hash<string>()(sd.isbn());
    }
    bool is_equal(const Sales_data& l, const Sales_data& r)
    {
        return l.isbn() == r.isbn();
    }

    using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(is_equal)*>;
    // 42: 桶大小
    SD_multiset booksetore(42, hasher, is_equal);
    ```