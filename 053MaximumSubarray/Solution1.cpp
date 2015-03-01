class Solution
{
public:
    int maxSubArray(int A[], int n)
    {
        int maxSum = 0;
        int maxSumEndWithCurrent = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                maxSum = maxSumEndWithCurrent = A[0];
                continue;
            }
            maxSumEndWithCurrent = maxSumEndWithCurrent > 0 ? maxSumEndWithCurrent + A[i] : A[i];
            maxSum = max(maxSum, maxSumEndWithCurrent);
        }

        return maxSum;
    }
};
