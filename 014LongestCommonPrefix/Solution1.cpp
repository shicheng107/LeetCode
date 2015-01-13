#include <vector>
#include <stdint.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(const vector<string> &strs)
    {
        if (strs.size() == 0) return "";
        string prefix;
        uint32_t index = 0;
        while (true)
        {
            char c = strs[0][index];
            if (c == '\0') return prefix;
            for (uint32_t i = 0; i < strs.size(); i++)
            {
                if (strs[i][index] == '\0' || strs[i][index] != c)
                    return prefix;
            }
            index++;
            prefix.push_back(c);
        }
        return prefix;
    }
};