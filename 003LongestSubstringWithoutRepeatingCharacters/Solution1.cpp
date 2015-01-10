/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
using namespace std;

// Time complexity: O(n^2).
// Space complexity: O(n^2).
#include <string>
#include <stdint.h>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(const string &s)
    {
        uint32_t maxCount = 0;
        for (uint32_t i = 0; i < s.length(); i++)
        {
            unordered_set<char> visited;
            uint32_t count = 0;
            for (uint32_t j = i; j < s.length(); j++)
            {
                if (visited.find(s[j]) != visited.end())
                    break;
                visited.insert(s[j]);
                count++;
            }
            if (count > maxCount)
                maxCount = count;
        }
        return maxCount;
    }
};

int main(int argc, const char** argv)
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;

    cin.get();
    return 0;
}
