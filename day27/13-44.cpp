#include "13-44.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
    auto start = alloc.allocate(e - b);
    return { start, std::uninitialized_copy(b, e, start) };
}

void String::range_initialize(const char* ps, const char* pe)
{
    auto pair = this->alloc_n_copy(ps, pe);
    this->element = pair.first;
    this->end = pair.second;
}

String::String(const char* pc)
{
    char* end = const_cast<char*>(pc);
    while (*end)
    {
        ++ end;
    }
    this->range_initialize(pc, ++ end);
}

String::String(const String& s)
{
    this->range_initialize(s.element, s.end);
    std::cout << "copy constructor" << std::endl;
}

void String::free()
{
    if (this->element)
    {
        std::for_each(this->element, this->end, [this](char& c) {
            this->alloc.destroy(&c);
        });
        alloc.deallocate(this->element, this->end - this->element);
        this->element = nullptr;
        this->end = nullptr;
    }
}

const String& String::operator=(const String& rhs)
{
    auto pair = this->alloc_n_copy(rhs.element, rhs.end);
    free();
    this->element = pair.first;
    this->end = pair.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

String::~String()
{
    this->free();
}

int main()
{
    std::cout << "????" << std::endl;
    std::vector<String> v;
    v.push_back("1");
    v.push_back("2");
    v.push_back("3");
}
