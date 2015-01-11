/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

// Average time complexity: O(min(m,n)).
// Average space complexity: O(1).
// Get the idea from https://oj.leetcode.com/discuss/15790/share-my-o-log-min-m-n-solution-with-explanation.
// This is the version that does not use binary search.
#include <string>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        if (m > n)
            return findMedianSortedArrays(B, n, A, m);
        if (m == 0 && n == 0)
            return 0;
        if (m == 0)
            return n & 1 ? B[(n - 1) / 2] : (B[(n - 1) / 2] + B[n / 2]) / 2.0;
        if (n == 0)
            return m & 1 ? A[(m - 1) / 2] : (A[(m - 1) / 2] + A[m / 2]) / 2.0;
        for (int i = 0; i <= m; i++)
        {
            int j = ((m + n + 1) >> 1) - i;
            if (i < m && j > 0 && A[i] < B[j - 1])
                continue;
            int num1 = 0;
            if (i == 0)
                num1 = B[j - 1];
            else if (j == 0)
                num1 = A[i - 1];
            else
                num1 = max(A[i - 1], B[j - 1]);
            if ((m + n) & 1)
                return num1;
            int num2 = 0;
            if (i == m)
                num2 = B[j];
            else if (j == n)
                num2 = A[i];
            else
                num2 = min(A[i], B[j]);
            return (num1 + num2) / 2.0;
        }
        return 0;
    }
};

int main(int argc, const char** argv)
{
    int A[] = { 100000 };
    int m = 1;
    int B[] = { 100001 };
    int n = 1;

    Solution s;
    cout << s.findMedianSortedArrays(A, m, B, n) << endl;

    cin.get();
    return 0;
}
