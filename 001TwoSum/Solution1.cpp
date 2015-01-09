/**
 * Cheng Shi, shicheng107@hotmail.com
 */

#include <iostream>

// The first idea would be iterate the array.
// The time complexity is O(n^2).

#include <stdint.h>
#include <utility>
#include <vector>

using namespace std;

typedef pair<uint32_t, uint32_t> IndexPair;

IndexPair GetTwoSum(const vector<int32_t> &numbers, int32_t sum)
{
    for (uint32_t i = 0; i < numbers.size(); i++)
    {
        for (uint32_t j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[i] + numbers[j] == sum)
            {
                return IndexPair(i + 1, j + 1);
            }
        }
    }
    return IndexPair(0, 0);
}

int main(int argc, const char** argv)
{
    vector<int32_t> numbers({1, 4, 2, 7, 3, 8, 9});
    IndexPair ip = GetTwoSum(numbers, 7);
    cout << ip.first << ", " << ip.second << endl;

    cin.get();
    return 0;
}
