/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;

namespace std
{
    template<>
    struct hash<vector<int> >
    {
        size_t operator ()(const vector<int> &v) const
        {
            size_t output = 0;
            for (uint32_t i = 0; i < v.size(); i++)
            {
                output += v[i];
                output *= v[i] % 10;
            }
            return output;
        }
    };
}

class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &num)
    {
        vector<vector<int> > output;
        if (num.size() < 3)
            return output;

        unordered_set<vector<int> > outputSet;
        unordered_map<int, int> outputMap;
        for (int i = 0; i < num.size(); i++)
            outputMap[num[i]]++;

        for (auto it = outputMap.begin(); it != outputMap.end(); ++it)
        {
            if (it->second == 0)
                continue;
            int sum = it->first;
            it->second--;
            for (auto it2 = outputMap.begin(); it2 != outputMap.end(); ++it2)
            {
                if (it2->second == 0)
                    continue;
                sum += it2->first;
                it2->second--;
                if (outputMap.find(-sum) != outputMap.end())
                {
                    vector<int> result;
                    result.push_back(it->first);
                    result.push_back(it2->first);
                    if (outputSet.find(result) == outputSet.end())
                    {
                        outputSet.insert(result);
                        result.push_back(-sum);
                        output.push_back(result);
                    }
                }
                it2->second++;
                sum -= it2->first;
            }
            it->second++;
        }
        return output;
    }
};

int main(int argc, const char** argv)
{
    Solution s;
    vector<vector<int> > v = s.threeSum(vector<int>({ -1, 0, 1, 5, -9, -11, 9, 9, -4, 14, 10, -11, 1, -13, 11, 10, 14, -3, -3, -4, 6, -15, 6, 6, -13, 7, -11, -15, 10, -8, 13, -14, -12, 12, 6, -6, 8, 0, 10, -11, -8, -2, -6, 8, 0, 12, 3, -9, -6, 8, 3, -15, 0, -6, -1, 3, 9, -5, -5, 4, 2, -15, -3, 5, 13, -11, 7, 6, -4, 2, 11, -5, 7, 12, -11, -15, 1, -1, -9, 10, -8, 1, 2, 8, 11, -14, -4, -3, -12, -2, 8, 5, -1, -9, -4, -3, -13, -12, -12, -10, -3, 6, 1, 12, 3, -3, 12, 11, 11, 10 }));
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    cout << "done" << endl;
    cin.get();
    return 0;
}
