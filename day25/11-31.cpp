#include <iostream>
#include <map>
#include <string>
int main()
{
    std::multimap<std::string, std::string> authors{
        { "alan", "DMA" },
        { "pezy", "LeetCode" },
        { "alan", "CLRS" },
        { "wang", "FTP" },
        { "pezy", "CP5" },
        { "wang", "CPP-Concurrency" }
    };

    std::string author = "pezy";
    std::string work = "CP5";

    auto count = authors.count(author);
    auto iter = authors.find(author);

    while (count > 0)
    {
        if (iter->second == work)
        {
            authors.erase(iter);
        }
        -- count;
        iter ++;
    }

    for (const auto& kv: authors)
    {
        std::cout << kv.first << ": " << kv.second << std::endl;
    }
}
