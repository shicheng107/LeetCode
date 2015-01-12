/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

// Time complexity: O(n).
// Space complexity: O(1).
// Based on the solution below.  It is rather simple after you've got it.
// https://oj.leetcode.com/discuss/1074/anyone-who-has-a-o-n-algorithm

#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(const vector<int> &height)
    {
        int mx = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right)
        {
            mx = max(mx, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return mx;
    }
};

int main(int argc, const char** argv)
{
    Solution s;
    cout << s.maxArea(vector<int>({ 1, 1 })) << endl;

    cin.get();
    return 0;
}
