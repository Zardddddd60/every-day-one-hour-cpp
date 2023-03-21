#pragma once

#include <memory>
#include <string>
#include <utility>

class StrVec
{
    public:
        StrVec():
            elem(nullptr), first_free(nullptr), cap(nullptr) {}
        StrVec(std::initializer_list<std::string>);
        StrVec(const StrVec&);
        const StrVec& operator=(const StrVec&);
        ~StrVec();
        void push_back(const std::string&);
        size_t size() const { return first_free - elem; }
        size_t capacity() const { return cap - elem; }
        std::string* begin() const { return elem; };
        std::string* end() const { return first_free; };
    private:
        static std::allocator<std::string> alloc;
        void reallocate();
        void check_n_allocate();
        void alloc_n_move(size_t);
        std::pair<std::string*, std::string*> alloc_n_copy
            (const std::string*, const std::string*);
        void free();
        void reserve(size_t);
        void resize(size_t, const std::string&);
        void range_initialize(const std::string*, const std::string*);

    private:
        std::string* elem;
        std::string* first_free;
        std::string* cap;
};
