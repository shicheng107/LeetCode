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
    int atoi(const char *str)
    {
        if (str == NULL) return 0;
        bool started = false;
        bool negative = false;
        uint32_t index = 0;
        int32_t output = 0;
        while (str[index] != NULL)
        {
            if (!started)
            {
                if (str[index] == ' ' || str[index] == '\t')
                    ;
                else if (str[index] == '+')
                    started = true;
                else if (str[index] == '-')
                {
                    negative = true;
                    started = true;
                }
                else if (str[index] >= '0' && str[index] <= '9')
                {
                    started = true;
                    index--;
                }
                else
                    return 0;
            }
            else
            {
                if (str[index] >= '0' && str[index] <= '9')
                {
                    int32_t digit = str[index] - '0';
                    if (output > numeric_limits<int32_t>::max() / 10)
                        return negative ? numeric_limits<int32_t>::min() : numeric_limits<int32_t>::max();
                    output *= 10;
                    if (output > numeric_limits<int32_t>::max() - digit)
                        return negative ? numeric_limits<int32_t>::min() : numeric_limits<int32_t>::max();
                    output += digit;
                }
                else
                    return negative ? -output : output;
            }
            index++;
        }
        return negative ? -output : output;
    }
};

int main(int argc, const char** argv)
{
    Solution s;
    cout << s.atoi("1") << endl;

    cin.get();
    return 0;
}
