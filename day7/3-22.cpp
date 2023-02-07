#include <cctype>
#include <iostream>
#include <string>
int main()
{
    std::string s = "There is a dog";
    for (auto iter = s.begin(); iter != s.end(); iter ++)
    {
        if (std::isspace(*iter))
        {
            break;
        }
        if (std::islower(*iter))
        {
            *iter = toupper(*iter);
        }
    }

    std::cout << s << std::endl;
}