/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &num, int target)
    {
        if (num.size() < 3)
            return 0;

        sort(num.begin(), num.end());
        int closestSum = 0;
        bool closestSet = false;


        for (int32_t i = 0; i < num.size() - 2; i++)
        {
            int32_t j = i + 1;
            int32_t k = num.size() - 1;

            do
            {
                int sum = num[i] + num[j] + num[k];
                if (closestSet)
                {
                    if (abs(sum - target) < abs(closestSum - target))
                        closestSum = sum;
                }
                else
                {
                    closestSum = sum;
                    closestSet = true;
                }
                sum <= target ? j++ : k--;
            } while (j < k);
        }
        return closestSum;
    }
};

int main(int argc, const char** argv)
{
    Solution s;
    cout << s.threeSumClosest(vector<int>({ 1, 1, 1, 0 }), -100) << endl;
    cout << "done" << endl;
    cin.get();
    return 0;
}
