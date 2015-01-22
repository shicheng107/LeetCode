class Solution
{
public:
    int search(int A[], int n, int target)
    {
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            if (target == A[l])
                return l;
            if (target == A[r])
                return r;
            int mid = (l + r) / 2;
            if (target == A[mid])
                return mid;
            if (target < A[mid])
            {
                if (A[l] < A[mid] && target < A[l])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
            {
                if (A[r] > A[mid] && target > A[r])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};