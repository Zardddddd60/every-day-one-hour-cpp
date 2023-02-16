#include "7-27.h"
#ifndef CP_7_32_h
#define CP_7_32_h
#include <vector>

class Screen1;

class Window_mgr
{
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
    private:
        std::vector<Screen1> screens;
    public:
        void clear(ScreenIndex i);
};

class Screen1
{
    friend void Window_mgr::clear(ScreenIndex i);
    public:
        using pos = std::string::size_type;
    private:
        std::string contents;
        pos width = 0, height = 0;
        pos cursor = 0;
};

inline void Window_mgr::clear(ScreenIndex i)
{
    auto& screen = screens[i];
    screen.contents = "";
}

#endif
