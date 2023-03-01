1. `vector`是连续存储的，所以当插入元素时，如果连续的存储空间不足时，会进行容器的内存空间的重新分配，把原空间的元素移动到新空间，并释放旧空间。
2. `capacity()`返回容器占据的空间，而`size()`返回容器中元素的个数。`size`总是小于等于`capacity`。`reserve()`只会增大容器占据的空间而不会退还。`shrink_to_fit()`可能会退还占据的空间`capacity`到`size`，但取决于具体实现。
3. 当使用c风格字符串`const char*`来定义`string`时，自带了结尾空字符，所以可以直接用来初始化`string`，而字符数组必须手动指定结尾的空字符或者指定一个有效长度，才能用来初始化`string`。而使用`string`来初始化`string`时，则没有这个限制。
4. `substr`生成一个新的`string`，是原先string的一个拷贝。`s.assign(const char*, int)`用于替换`s`的内容，`s.insert(int, const char*)`用于给`s`插入一段字符。`s.append(const char*)`用于在s后边添加字符。`s.insert(int, const char*)`用于在指定位置插入字符。`s.erase(int, int)`用于删除s中执行位置指定数量的字符。`s.replace(int, int, const char*)`类似与`splice`方法，删除并插入。
5. string的`find`方法返回`string::size_type`类型的值，当没有找到相应的字符时，返回`string::npos`。`s.find_first_of(string s1)`返回`s`中，存在于参数`s1`的第一个字符的位置。
6. 适配器是一种机制，使某种事物的行为看起来像另一种事物。一个适配器接受一种已有的容器类型，使其行为看起来像一种不同的类型。
7. 默认情况下，`stack`和`queue`基于`deque`实现，`priority_queue`基于`vector`实现。可以通过创建适配器时，通过指定容器的方式，指定容器类型。
    ```cpp
    stack<string, vector<string>> str_stk(svec);
    ```
8. `stack`需要完成`push_back`，`pop_back`和`back`，所以容器可以选择除`array`和`forward_list`外的其他容器。`queue`可以构造与`list`和`deque`之上。`priority_queue`可以基于`vector`和`deque`。