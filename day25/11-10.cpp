#include <list>
#include <map>
#include <utility>
#include <vector>
int main()
{
    std::map<std::vector<int>::iterator, int> mi;
    std::map<std::list<int>::iterator, int> ml;

    std::vector<int> vi;
    std::list<int> li;
    mi.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0));
    // mv.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0));
    ml.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0));
}