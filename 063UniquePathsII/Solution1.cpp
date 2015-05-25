#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct Pt
{
    Pt(int inX, int inY) : x(inX), y(inY) {}
    int x;
    int y;
};

namespace std
{
    template<>
    struct hash<Pt>
    {
        size_t operator()(const Pt &pt) const
        {
            return hash<int>()(pt.x) ^ hash<int>()(pt.y);
        }
    };

    template <>
    struct equal_to<Pt>
    {
       size_t operator()(const Pt &pt1, const Pt &pt2) const
       {
           return pt1.x == pt2.x && pt1.y == pt2.y;
       }
    };
}

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid)
    {
        grid = &obstacleGrid;
        maxX = grid->size() - 1;
        maxY = 0;
        if (maxX >= 0)
            maxY = (*grid)[0].size() - 1;

        return uniquePathsWithObstacles(0, 0);
    }


    int uniquePathsWithObstacles(int x, int y)
    {
        if ((*grid)[x][y] != 0)
            return 0;
        if (x == maxX && y == maxY)
            return 1;
        Pt p(x, y);
        if (results.find(p) != results.end())
            return results[p];
        int count = 0;
        if (x + 1 <= maxX && (*grid)[x + 1][y] == 0)
            count += uniquePathsWithObstacles(x + 1, y);
        if (y + 1 <= maxY && (*grid)[x][y + 1] == 0)
            count += uniquePathsWithObstacles(x, y + 1);
        results[p] = count;
        return count;
    }

    int maxX;
    int maxY;
    vector<vector<int> > *grid;
    unordered_map<Pt, int> results;
};

int main(int argc, const char **argv)
{
    vector<vector<int> > v;
    vector<int> row1({0, 1});
    v.push_back(row1);

    Solution s;
    cout << s.uniquePathsWithObstacles(v) << endl;
    return 0;
}
