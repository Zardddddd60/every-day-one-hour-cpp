#pragma once

#include <string>

class HasPtr
{
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
                delete ps;
                delete count;
            }
        }
        
    private:
        size_t* count;
        std::string* ps;
};
