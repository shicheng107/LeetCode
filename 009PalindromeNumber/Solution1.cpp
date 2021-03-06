/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

#include <limits>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        return x == reverse(x);
    }

    int reverse(int x)
    {
        bool minus = x < 0;
        x = abs(x);
        int32_t output = 0;
        while (x > 0)
        {
            if (output > numeric_limits<int32_t>::max() / 10)
                return 0;
            output *= 10;
            int32_t left = x % 10;
            if (output > numeric_limits<int32_t>::max() - left)
                return 0;
            output += left;
            x /= 10;
        }
        return minus ? -output : output;
    }
};

int main(int argc, const char** argv)
{
    cin.get();
    return 0;
}
