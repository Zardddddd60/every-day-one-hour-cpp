#include <iostream>
#include <memory>
#include <string>
#include <sys/_types/_size_t.h>
int main()
{
    const int n = 10;
    std::allocator<std::string> alloc;
    auto p = alloc.allocate(n);
    auto q = p;
    std::string s;
    while (std::cin >> s)
    {
        alloc.construct(q ++, s);
    }
    size_t sz = q - p;
    for (auto i = 0; i < sz; ++ i)
    {
        std::cout << *(p + i) << std::endl;
    }

    while (q != p)
    {
        alloc.destroy(--q);
    }
    alloc.deallocate(p, n);
}