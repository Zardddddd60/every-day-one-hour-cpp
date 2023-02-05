1. 使用`using`声明，可以引入指定命名空间(namespace)的成员。一般来说不应在头文件使用`using`，否则可能在引入头文件的文件中，也引入这些声明。
2. 使用`cin`作为`string`对象的输入时，会自动去掉字符前的空格部分，以空格作为一串字符的结束。在`while`中检测的是流的状态。
    ```cpp
    string s;
    while (cin >> s) // 输入" Hello World "，会进入两次循环
    {}
    ```
3. 使用`getline(istream, string)`读取流信息到string中，会保留换行符之前的所有字符和空格信息。读入到string的信息不包括换行符。它返回istream，所以可以像`cin`一样，在`while`循环中不断读取。
4. `string`的`size()`用于返回string的长度，注意它的返回类型是一个无符号数`string::size_type`，体现了标注库机器无关的特性。可以用`auto`来承接返回值。注意它是一个**无符号数**，所以当它与一个int做比较时，负int值会装成一个较大无符号数，导致判断出问题。
> 尽量不要混用无符号数和有符号数。
5. `string`的比较运算法比较的是第一个不同的字符的字典顺序。
6. string与字符字面值和字符串字面值相加。必须保证`+`的两侧**至少**有一个string对象，那么字符字面值或字符串字面值会被转成string对象。注意两个字符串字面值是不能直接相加的。
    ```cpp
    string s1 = "";
    // 合法，s1先和前面的字面值生成string，再与后边相加
    string s2 = s1 + ", " + "World";
    // 不合法，两个字面值不能直接相加
    string s3 = "Hello" + ", " + s1;
    ```
7. 标准库中，c语言的头文件形为`name.h`，c++的头文件为`cname`。在名为`cname`的头文件定义的名字属于命名空间`std`，而c的头文件则不属于任何命名空间。一般来说，要使用c++的头文件。比如`cctype`中用于判断字符类型的函数。
8. 使用`for`来遍历string，注意使用`auto`时，会把string内的每一个字符**复制**过来，因此在for内修改字符不会对原本的string造成影响，可以通过引用来引用到string的字符。
```cpp
for (auto c: s1) {}

for (auto& c: s1) {
    // cctype
    c = std::toupper(c);
}
```
9. 因为引用不是一个对象，所以不存在引用类型的vertor。可以使用**列表初始化**的方式，创建包含多个对象的vector。
    ```cpp
    vector<int> v { 1, 2, 3 };

    vector<int> v1(10); // 10个int，初始值为0（默认）；
    vector<int> v1{10}; // 一个int
    vector<int> v1(10, 10); // 10个int，初始值为10；
    vector<int> v1{10, 10}; // 2个值为10的int
     ```
