/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

namespace std
{
    template<>
    struct hash<vector<int> >
    {
        size_t operator()(const vector<int> &v)
        {
            size_t h = 0;
            for (int i = 0; i < v.size(); i++)
                h += 13 + v[i] * 31;
            return h;
        }
    };

    template<>
    struct equal_to<vector<int> >
    {
        bool operator()(const vector<int> &v1, const vector<int> &v2)
        {
            if (v1.size() != v2.size())
                return false;
            for (int i = 0; i < v1.size(); i++)
            {
                if (v1[i] != v2[i])
                    return false;
            }
            return true;
        }
    };
};

class Solution {
public:
    struct TwoSum
    {
        TwoSum(int _a, int _b, int _ia, int _ib, int _sum)
            : a(_a), b(_b), ia(_ia), ib(_ib), sum(_sum) {}
        bool IsOverLap(const TwoSum &other)
        {
            if (ia == other.ia || ia == other.ib
                || ib == other.ia || ib == other.ib)
                return false;
            return true;
        }
        int a;
        int b;
        int ia;
        int ib;
        int sum;

    };

    // This does work in GCC.
    //struct hash
    //{
    //    size_t operator()(const vector<int> &v)
    //    {
    //        size_t h = 0;
    //        for (int i = 0; i < v.size(); i++)
    //            h += 13 + v[i] * 31;
    //        return h;
    //    }
    //};

    //struct equal_to
    //{
    //    bool operator()(const vector<int> &v1, const vector<int> &v2)
    //    {
    //        if (v1.size() != v2.size())
    //            return false;
    //        for (int i = 0; i < v1.size(); i++)
    //        {
    //            if (v1[i] != v2[i])
    //                return false;
    //        }
    //        return true;
    //    }
    //};

    vector<vector<int> > fourSum(vector<int> &num, int target)
    {
        vector<vector<int> > output;
        if (num.size() < 4)
            return output;
        vector<TwoSum> tss;
        for (int i = 0; i < num.size(); i++)
        {
            for (int j = i + 1; j < num.size(); j++)
            {
                TwoSum ts(num[i], num[j], i, j, num[i] + num[j]);
                tss.push_back(ts);
            }
        }
        unordered_set<vector<int> > s;
        for (int i = 0; i < tss.size(); i++)
        {
            for (int j = i + 1; j < tss.size(); j++)
            {
                if (tss[i].sum + tss[j].sum == target && !tss[i].IsOverLap(tss[j]))
                {
                    vector<int> candidate({ tss[i].a, tss[i].b, tss[j].a, tss[j].b });
                    sort(candidate.begin(), candidate.end());
                    if (s.find(candidate) != s.end())
                    {
                        s.insert(candidate);
                        output.push_back(candidate);
                    }
                }
            }
        }
        return output;
    }
};

int main(int argc, const char** argv)
{
    Solution s;
    vector<vector<int> > v = s.fourSum(vector<int>({ -455, -408, -383, -374, -347, -344, -320, -319, -266, -252, -170, -120, -113, -104, -100, -81, -64, -48, -46, -44, -4, -1, 26, 28, 30, 62, 69, 84, 100, 119, 126, 134, 144, 145, 170, 179, 230, 246, 264, 269, 272, 289, 294, 323, 328, 331, 335, 336, 370, 370, 388, 394, 397, 400, 427, 431, 452, 483 }), 5842);
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
