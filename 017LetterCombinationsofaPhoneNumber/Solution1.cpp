/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

#include <vector>
#include <string>
using namespace std;

string Mapping[] =
{
    "",     // 0
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

class Solution
{
public:
    vector<string> letterCombinations(const string &digits)
    {
        vector<string> output;
        if (digits.empty())
        {
            output.push_back("");
            return output;
        }
        char last = digits[digits.size() - 1];
        vector<string> sub = letterCombinations(digits.substr(0, digits.size() - 1));
        if (last < '2' || last > '9')
            return sub;
        int index = last - '0';
        for (int i = 0; i < Mapping[index].size(); i++)
        {
            if (sub.empty())
                output.push_back(string(1, Mapping[index][i]));
            for (int j = 0; j < sub.size(); j++)
                output.push_back(sub[j] + Mapping[index][i]);
        }
        return output;
    }
};

int main(int argc, const char** argv)
{
    Solution s;
    vector<string> v = s.letterCombinations("123");
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        cout << endl;
    }
    cout << "done" << endl;
    cin.get();
    return 0;
}
