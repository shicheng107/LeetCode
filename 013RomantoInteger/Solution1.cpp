/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

#include <string>
using namespace std;

class Solution
{
public:
    int romanToInt(const string &s)
    {
        int values[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
        const char *symbols[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
        int index = sizeof(values) / sizeof(values[0]) - 1;
        const char *p = s.c_str();
        int num = 0;
        while (*p != '\0')
        {
            if (strstr(p, symbols[index]) != NULL)
            {
                num += values[index];
                p += strlen(symbols[index]);
            }
            else
            {
                index--;
                if (index < 0)
                    break;
            }
        }
        return num;
    }
};


int main(int argc, const char** argv)
{
    Solution s;
    for (int i = 1; i < 3999; i++)
        cout << i << " " << s.intToRoman(i) << endl;

    cin.get();
    return 0;
}
