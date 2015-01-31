class Solution
{
public:
    int trap(int A[], int n)
    {
        int l = 0;
        int r = n - 1;
        int water = 0;
        int maxl = 0;
        int maxr = 0;
        while (l < r)
        {
            if (A[l] <= A[r])
            {
                if (A[l] > maxl)
                    maxl = A[l];
                else
                    water += maxl - A[l];
                l++;
            }
            else
            {
                if (A[r] > maxr)
                    maxr = A[r];
                else
                    water += maxr - A[r];
                r--;
            }
        }
        return water;
    }
};