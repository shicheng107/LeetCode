/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

// Average time complexity: O(n)?  I am not so sure.
// Average space complexity: O(n).
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(const string &s)
    {
        vector<uint32_t> substringLength(s.length(), 0);
        uint32_t maxLength = 0;
        int32_t index = 0;
        for (int32_t i = 0; i < s.length(); i++)
        {
            if (i == 0)
            {
                substringLength[i] = 1;
                maxLength = 1;
            }
            else
            {
                if (isPalindromic(s, i - maxLength - 1, i))
                {
                    index = i - maxLength - 1;
                    maxLength += 2;
                }
                else if (isPalindromic(s, i - maxLength, i))
                {
                    index = i - maxLength;
                    maxLength += 1;
                }
                substringLength[i] = maxLength;
            }
        }
        return s.substr(index, maxLength);
    }

    bool isPalindromic(const string &s, int32_t min, int32_t max)
    {
        if (min < 0 || max > s.length() - 1)
            return false;
        while (min < max)
        {
            if (s[min++] != s[max--])
                return false;
        }
        return true;
    }
};

int main(int argc, const char** argv)
{
    Solution s;
    cout << s.longestPalindrome("ccd").c_str() << endl;

    cin.get();
    return 0;
}
