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

        for (auto i = 0; i < num.size(); i++)
        {
            unordered_set<int> m;
            for (auto j = i + 1; j < num.size(); j++)
            {
                if (m.find(-num[i] - num[j]) != m.end())
                {
                    vector<int> candidate({ num[i], num[j], -num[i] - num[j] });
                    sort(candidate.begin(), candidate.end());
                    if (outputSet.find(candidate) == outputSet.end())
                    {
                        output.push_back(candidate);
                        outputSet.insert(candidate);
                    }
                }
                m.insert(num[j]);
            }
        }

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
                    result.push_back(-sum);
                    sort(result.begin(), result.end());
                    if (outputSet.find(result) == outputSet.end())
                    {
                        outputSet.insert(result);
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
    vector<vector<int> > v = s.threeSum(vector<int>({ 7, -1, 14, -12, -8, 7, 2, -15, 8, 8, -8, -14, -4, -5, 7, 9, 11, -4, -15, -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 1, -1, 4, -6, -15, 1, 5, -15, 10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, -4, -1, -12, -2, 14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0, 5, 14, -1, 14, 3, 8, 10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12, 8, 6, -13, 14, -2, -5, -11, 1, 3, -6 }));
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
