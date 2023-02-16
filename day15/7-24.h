#pragma once

#include <string>
class Screen
{
    public:
        using pos = std::string::size_type;
    private:
        pos cursor = 0;
        pos width = 0;
        pos height = 0;
        std::string contents;
    public:
        Screen() = default;
        Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {};
        Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {};
        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r * width + c]; };
};
