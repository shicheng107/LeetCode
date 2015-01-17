/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> sk;
        for_each(s.begin(), s.end(), [&](char c)
        {
            if (!isValidChar(c))
                return false;
            if (!sk.empty() && isPair(sk.top(), c))
                sk.pop();
            else
                sk.push(c);
        });
        return sk.empty();
    }

    bool isValidChar(char c)
    {
        return c == '{' || c == '}' || c == '[' || c == ']' || c == '(' || c == ')';
    }

    bool isPair(char a, char b)
    {
        if (a == '{' && b == '}'
            || a == '[' && b == ']'
            || a == '(' && b == ')')
            return true;
        return false;
    }
};

int main(int argc, const char** argv)
{
    Solution s;
    s.isValid("{[]}");
    cout << "done" << endl;
    cin.get();
    return 0;
}
