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
    int uniquePaths(int m, int n)
    {
        if (m <= 0 || n <= 0)
            return 0;
        if (m == 1 && n == 1)
            return 1;
        if (m == 2 && n == 1 || m == 1 && n == 2)
            return 1;
        if (results.find(Pt(m, n)) != results.end())
            return results[Pt(m, n)];
        int result = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
        results[Pt(m, n)] = result;
        return result;
    }

    unordered_map<Pt, int> results;
};
