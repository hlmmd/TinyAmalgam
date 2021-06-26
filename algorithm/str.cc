#include "str.h"
#include <vector>
namespace hl
{
namespace algorithm
{
namespace string
{

int SubStr(const std::string& text, const std::string& pattern)
{
    if (pattern.size() == 0)
        return 0;
    auto getNext = [](const std::string& pattern) -> std::vector<int> {
        int n = pattern.size();
        std::vector<int> next(n, 0);
        int prefixlen = 0;
        for (int i = 1; i < n; i++)
        {
            if (pattern[i] == pattern[prefixlen])
            {
                next[i] = ++prefixlen;
            }
            else
            {
                if (prefixlen > 0)
                {
                    prefixlen = next[prefixlen - 1];
                    i--;
                }
                else
                    next[i] = 0;
            }
        }

        return next;
    };

    auto next = getNext(pattern);
    for (int i = 0, j = 0; i < text.size(); i++)
    {
        if (text[i] == pattern[j])
        {
            j++;
            if (j == pattern.size())
                return i - j + 1;
        }
        else
        {
            if (j != 0)
            {
                j = next[j - 1];
                i--;
            }
        }
    }
    return -1;
}
} // namespace string
} // namespace algorithm
} // namespace hl

