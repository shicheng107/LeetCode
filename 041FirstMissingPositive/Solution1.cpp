class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return A[0] == 1 ? 2 : 1;
        
        for (int i = 0; i < n; i++)
        {
            if (A[i] <= 0 || A[i] > n)
                continue;
            while (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[A[i] - 1], A[i]);
        }
        for (int i = 0; i < n; i++)
            if (A[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};
