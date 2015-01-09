/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>

// This solution is to use a map to remember the numbers visited
// so 1 iteration is enough.
// The time complexity is O(n).

#include <stdint.h>
#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

typedef pair<uint32_t, uint32_t> IndexPair;
typedef unordered_map<int32_t, uint32_t> DataWithIndex;

IndexPair GetTwoSum(const vector<int32_t> &numbers, int32_t sum)
{
    DataWithIndex dataWithIndex;
    for (uint32_t i = 0; i < numbers.size(); i++)
    {
        int32_t left = sum - numbers[i];
        if (dataWithIndex.find(left) != dataWithIndex.end())
            return IndexPair(dataWithIndex[left], i + 1);
        if (dataWithIndex.find(numbers[i]) == dataWithIndex.end())
            dataWithIndex.insert(make_pair(numbers[i], i + 1));
    }
    return IndexPair(0, 0);
}

int main(int argc, const char** argv)
{
    vector<int32_t> numbers({ 1, 4, 2, 7, 3, 8, 9 });
    IndexPair ip = GetTwoSum(numbers, 7);
    cout << ip.first << ", " << ip.second << endl;

    cin.get();
    return 0;
}
