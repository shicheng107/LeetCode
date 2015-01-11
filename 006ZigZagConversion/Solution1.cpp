/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

// The average time complexity is O(n).
// The average space complexity is O(n) too.
#include <vector>

class Solution
{
public:
    string convert(string s, int nRows)
    {
        vector<string> output(nRows, "");
        bool goDown = true;
        int32_t rowIndex = 0;
        for (uint32_t i = 0; i < s.length(); i++)
        {
            output[rowIndex].push_back(s[i]);
            if (rowIndex == nRows - 1)
                goDown = false;
            if (rowIndex == 0)
                goDown = true;
            rowIndex = goDown ? (rowIndex + 1) : (rowIndex - 1);

            // There will be run time error after the solution submission
            // if the following lines are commented out.
            if (rowIndex >= output.size())
                rowIndex = output.size() - 1;
            if (rowIndex < 0)
                rowIndex = 0;
        }
        string result;
        for (auto it = output.begin(); it != output.end(); ++it)
            result += *it;
        return result;
    }
};

int main(int argc, const char** argv)
{
    Solution s;
    cout << s.convert("AB", 2).c_str() << endl;

    cin.get();
    return 0;
}
