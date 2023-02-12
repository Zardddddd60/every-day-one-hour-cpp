#include <iostream>
int* foo()
{
    int i = 5;
    // return &i; // warning: Address of stack memory associated with local variable 'i' returned
    int* j = &i;
    return j;
}
int main()
{
    int* j = foo();
    std::cout << *j << std::endl; // 两种方式都能打印出5
}