#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
class StrBlob
{
    public:
        using size_type = std::vector<std::string>::size_type;
        StrBlob();
        StrBlob(std::initializer_list<std::string>);
        size_type size() const { return data->size(); };
        bool empty() const { return data->empty(); };
        void push_back(const std::string& s) { data->push_back(s); };
        void pop_back();
        std::string& front();
        std::string& back();
        const std::string& front() const;
        const std::string& back() const;
    private:
        void check(size_type i, std::string msg) const ;
        std::shared_ptr<std::vector<std::string>> data;
};

StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il):
    data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, std::string msg) const
{
    if (i >= this->size())
    {
        throw std::out_of_range(msg);
    }
}

void StrBlob::pop_back()
{
    this->check(0, "pop back on empty StrBlob");
    data->pop_back();
}

std::string& StrBlob::front()
{
    this->check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back()
{
    this->check(0, "back on empty StrBlob");
    return data->back();
}

const std::string& StrBlob::front() const
{
    this->check(0, "front on empty StrBlob");
    return data->front();
}

const std::string& StrBlob::back() const
{
    this->check(0, "back on empty StrBlob");
    return data->back();
}

int main()
{
    StrBlob sb;
    sb.push_back("ldd");
    std::cout << sb.front() << std::endl;

    const StrBlob csb({ "ysy", "ldd" });
    std::cout << csb.front() << std::endl;
}
