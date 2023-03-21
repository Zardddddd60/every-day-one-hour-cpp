#pragma once

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <sys/_types/_size_t.h>
#include <vector>

using element_type = std::vector<std::string>;

class ConstStrBlobPtr;
class StrBlob
{
    public:
        using size_type = element_type::size_type;
        friend ConstStrBlobPtr;

        ConstStrBlobPtr begin() const;
        ConstStrBlobPtr end() const;

        StrBlob():
            data(std::make_shared<element_type>()) {};
        StrBlob(const std::initializer_list<std::string> list):
            data(std::make_shared<element_type>(list)) {};
        
        StrBlob(const StrBlob& sb):
            data(std::make_shared<element_type>(sb.data)) {};
        const StrBlob& operator= (const StrBlob& sb);

        size_type size() const { return data->size(); };
        bool empty() const { return data->empty(); };
        void push_back(const std::string& s)
        {
            data->push_back(s);
        }; 
        void pop_back()
        {
            check(0, "pop_back on empty StrBlob");
            data->pop_back();
        }
        std::string& front()
        {
            check(0, "front on empty StrBlob");
            return data->front();
        }
        std::string& back()
        {
            check(0, "back on empty StrBlob");
            return data->back();
        }
        

    private:
        void check(size_type i, const std::string& msg) const
        {
            if (i >= data->size())
            {
                throw std::out_of_range(msg);
            }
        }
    private:
        std::shared_ptr<element_type> data;
};

class ConstStrBlobPtr
{
    public:
        ConstStrBlobPtr():
            curr(0) {};
        ConstStrBlobPtr(const StrBlob& sb, size_t i):
            wptr(sb.data), curr(i) {}
        
    public:
        const std::string& deref() const {
            auto p = check(curr, "dereference past end");
            return (*p)[curr];
        }
        ConstStrBlobPtr& incr() {
            check(curr, "increment past end of StrBlobPtr");
            ++ curr;
            return *this;
        }
    private:
        std::shared_ptr<element_type> check(size_t i, const std::string& msg) const
        {
            auto ret  = wptr.lock();
            if (!ret)
            {
                throw std::runtime_error("unbound StrBlobPtr");
            }
            if (i >= ret->size())
            {
                throw std::out_of_range(msg);
            }
            return ret;
        }
    private:
        std::weak_ptr<element_type> wptr;
        size_t curr;
};
