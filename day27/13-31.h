#pragma once

#include <__hash_table>
#include <__split_buffer>
#include <iostream>
#include <string>

class HasPtr
{
    public:
        friend void swap(HasPtr&, HasPtr&);
        friend bool operator<(const HasPtr&, const HasPtr&);
    public:
        HasPtr():
            count(new size_t()), ps(new std::string()) {}
        HasPtr(const std::string& s):
            count(new size_t()), ps(new std::string(s)) {}
        HasPtr(const HasPtr& rhs):
            count(rhs.count), ps(rhs.ps)
        {
            ++ (*rhs.count);
        }
        const HasPtr& operator= (const HasPtr& rhs)
        {
            // ps = rhs.ps;
            if (-- (*this->count) == 0)
            {
                delete ps;
                delete count;
            }
            this->ps = rhs.ps;
            this->count = rhs.count;
            ++ (*this->count);

            return *this;
        }
        ~HasPtr()
        {
            if (-- (*this->count) == 0)
            {
                std::cout << "deleting ...." << std::endl;
                delete ps;
                delete count;
            }
        }
        void show() const
        {
            std::cout << *ps << std::endl;
        }
        
    private:
        size_t* count;
        std::string* ps;
};

// swap 是inline的
inline void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.count, rhs.count);
    std::cout << "swap happens" << std::endl;
}

inline bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{
    return *lhs.ps < *rhs.ps;
}
