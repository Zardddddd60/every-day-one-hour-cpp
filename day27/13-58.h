#pragma once

#include <vector>
class Foo
{
    public:
        Foo sorted() const &;
        Foo sorted() &&;

    private:
        std::vector<int> data;
};
