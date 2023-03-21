#include "13-31.h"
#include <algorithm>
#include <vector>

int main()
{
    HasPtr a("3");
    HasPtr b("2");
    HasPtr c("1");

    std::vector<HasPtr> v {
        a, b, c
    };

    std::sort(v.begin(), v.end());

    for (const auto& item: v)
    {
        item.show();
    }
}
