1. 形参初始化的机理和变量初始化一样。如果形参是引用类型，则它被绑定到对应的实参上，否则将实参的值**拷贝后**赋给形参。
2. 如果函数无须改变引用形参的值，最好声明为常量引用。
3. 尽量使用常量引用。
   1. 不使用常量引用会给函数调用者实参会被改变的错觉；
   2. 常量形参既可以接受非常量实参（保证不在函数内改，string 接受一个字符串常量），也可以接受常量实参。
   3. 根据3.2中所说的，`(const int i)`和`(int i)`是同一种类型，无法进行重载（Redefinition of 'fn'）。因为调用`fn(i)`时不知道应该使用哪个函数。
4. 数组类型的形参也可以表示成指针类型，`(const int* arr)`，`(const int arr[])`和`(const int arr[10])`含义相同。二位数组的传入，因为是一个指向数组的数组，所以形式为`int (*p) [10]`，表示指向10个int元素的指针，也可以使用这种定义：`int matrix[][10];`。
5. 运行程序的参数会保存在main函数的形参中 `main(int argc, char* argv[])`。`argc`是`argv`的长度。`argv`的第一个元素是程序名，所以从第二个开始是用户的程序输入。
6. 可以使用`initializer_list`来表示个数不定的，类型相同的形参。`void fn(int code, initializer_list<string> errorList)`。然后使用`fn(100, {"error1", "error2"})`来初始化它，注意使用列表赋值。