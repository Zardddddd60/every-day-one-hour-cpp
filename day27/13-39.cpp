#include "13-39.h"
#include <alloca.h>
#include <iostream>
#include <memory>

StrVec::StrVec(std::initializer_list<std::string> il)
{
    this->range_initialize(il.begin(), il.end());
}


StrVec::StrVec(const StrVec& sv)
{
    this->range_initialize(sv.begin(), sv.end());
    std::cout << "copy constructor" << std::endl;
}

const StrVec& StrVec::operator=(const StrVec& sv)
{
    this->free();
    this->range_initialize(sv.begin(), sv.end());
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

StrVec::~StrVec()
{
    this->free();
}

void StrVec::range_initialize(const std::string* b, const std::string* e)
{
    auto pair = this->alloc_n_copy(b, e);
    this->elem = pair.first;
    this->first_free = pair.second;
    this->cap = pair.second;
}

void StrVec::push_back(const std::string& s)
{
    this->check_n_allocate();
    alloc.construct(this->first_free ++, s);
}

void StrVec::reallocate()
{
    auto new_capacity = this->size() ? 2 * this->size() : 1;
    this->alloc_n_move(new_capacity);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy
    (const std::string* b, const std::string* e)
{
    auto p = alloc.allocate(e - b);
    return { p, std::uninitialized_copy(b, e, p)};
}

void StrVec::check_n_allocate()
{
    if (this->size() == this->capacity())
    {
        this->reallocate();
    }
}

void StrVec::free()
{
    if (this->elem)
    {
        for (auto ps = this->elem; ps != this->first_free; ++ ps)
        {
            alloc.destroy(ps);
        }
        alloc.deallocate(this->elem, this->capacity());
    }
}

void StrVec::alloc_n_move(size_t count)
{
    auto new_elem = alloc.allocate(count);
    auto target = new_elem;
    for (auto op = this->elem; op != this->first_free; ++ op)
    {
        alloc.construct(target ++, std::move(*op));
    }
    this->free();
    this->first_free = target;
    this->elem = new_elem;
    this->cap = new_elem + count;
}

void StrVec::reserve(size_t count)
{
    if (count < this->capacity())
    {
        return;
    }
    this->alloc_n_move(count);
}

void StrVec::resize(size_t count, const std::string& s)
{
    if (count > this->size())
    {
        if (count > this->capacity())
        {
            this->reserve(count);
        }
        for (auto p = this->first_free; p != this->cap; ++ p)
        {
            alloc.construct(p, s);
        }
        this->first_free = this->cap;
    }
    else if (count < this->size())
    {
        while (this->first_free != this->elem + count)
        {
            alloc.destroy(this->first_free);
            -- this->first_free;
        }
    }
}

