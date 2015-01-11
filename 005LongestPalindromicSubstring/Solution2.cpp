/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

// Manacher's algorithm with 0(n) time complexity.
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string longestPalindrome(const string &s)
    {
        string ss = AddSeparator(s);
        vector<int32_t> p(ss.length(), 0);
        int32_t index = 0;
        int32_t right = 0;
        int32_t maxP = 0;
        for (int32_t i = 0; i < ss.length(); i++)
        {
            int32_t mirrorIndex = 2 * index - i;
            if (right > i)
                p[i] = min(p[mirrorIndex], right - i);
            else
                p[i] = 1;
            while (i + p[i] < ss.length() && i - p[i] >= 0 && ss[i + p[i]] == ss[i - p[i]])
                p[i]++;
            if (p[i] > maxP)
            {
                index = i;
                right = i + p[i];
                maxP = p[i];
            }
        }
        return RemoveSeparator(ss.substr(index - maxP + 1, maxP * 2 - 1));
    }

    uint8_t SEPARATOR = '\07';

    string AddSeparator(const string &s)
    {
        string output;
        output.reserve(s.length() * 2 + 1);
        for (uint32_t i = 0; i < s.length(); i++)
        {
            output.push_back(SEPARATOR);
            output.push_back(s[i]);
        }
        output.push_back(SEPARATOR);
        return output;
    }

    string RemoveSeparator(const string &s)
    {
        string output;
        for (uint32_t i = 0; i < s.length(); i++)
        {
            if (s[i] != SEPARATOR)
            {
                output.push_back(s[i]);
            }
        }
        return output;
    }
};

int main(int argc, const char** argv)
{
    Solution s;
    cout << s.longestPalindrome("ccd").c_str() << endl;

    cin.get();
    return 0;
}
