/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;


// This is the code for submission.

#include <vector>
#include <unordered_map>
using namespace std;

typedef unordered_map<int32_t, uint32_t> DataWithIndex;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        DataWithIndex dataWithIndex;
        for (uint32_t i = 0; i < numbers.size(); i++)
        {
            int32_t left = target - numbers[i];
            if (dataWithIndex.find(left) != dataWithIndex.end())
            {
                vector<int32_t> result;
                result.push_back(dataWithIndex[left]);
                result.push_back(i + 1);
                return result;
            }
            if (dataWithIndex.find(numbers[i]) == dataWithIndex.end())
                dataWithIndex.insert(make_pair(numbers[i], i + 1));
        }
        return vector<int32_t>(2, 0);
    }
};

int main(int argc, const char** argv)
{
    Solution s;
    vector<int32_t> t = s.twoSum(vector<int32_t>({ 3, 2, 4 }), 6);
    cout << t[0] << "," << t[1] << endl;

    cin.get();
    return 0;
}
