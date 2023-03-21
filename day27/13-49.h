#pragma once

#include <memory>

class String
{
    public:
        String(): String("") {};
        String(const char*);
        String(const String&);
        String(String&&) noexcept;
        const String& operator=(const String&);
        const String& operator=(String&&) noexcept;
        ~String();

        const char* c_str() const { return this->element; };
        size_t size() const { return end - element; };
        size_t length() const { return end - element - 1; };

    private:
        std::pair<char*, char*> alloc_n_copy(const char*, const char*);
        void range_initialize(const char*, const char*);
        void free();
    private:
        char* element;
        char* end;
        std::allocator<char> alloc;
};
