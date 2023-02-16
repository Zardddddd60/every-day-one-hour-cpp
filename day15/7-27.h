#ifndef CP_7_27_h
#define CP_7_27_h

#include <ostream>
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
        inline Screen& move(pos x, pos y);
        inline Screen& set(char c);
        inline Screen& set(pos x, pos y, char c);
        inline Screen& display(std::ostream& os);
        inline const Screen& display(std::ostream& os) const;
};

Screen& Screen::move(pos x, pos y)
{
    cursor = x + width + y;
    return *this;
};

Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

Screen& Screen::set(pos x, pos y, char c)
{
    contents[x * width + y] = c;
    return *this;
}

Screen& Screen::display(std::ostream& os)
{
    os << contents;
    return *this;
}

const Screen& Screen::display(std::ostream& os) const
{
    os << contents;
    return *this;
}

#endif
