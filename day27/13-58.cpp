#include "13-58.h"
#include <algorithm>
#include <iostream>

Foo Foo::sorted() const &
{
    std::cout << "const &" << std::endl;
    Foo foo(*this);
    std::sort(foo.data.begin(), foo.data.end());
    return foo;
}

Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    std::cout << "&&" << std::endl;
    return *this;
}

int main()
{
    Foo().sorted(); // call "&&"
    Foo f;
    f.sorted(); // call "const &"
}
