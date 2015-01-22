class Solution
{
public:
    vector<int> searchRange(int A[], int n, int target)
    {
        int l = 0;
        int r = n - 1;
        int index = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (A[mid] == target)
            {
                index = mid;
                break;
            }
            if (A[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (index == -1)
            return vector<int>(2, -1);
        l = 0;
        r = index;
        int left = index;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (A[mid] == target)
            {
                left = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        l = index;
        r = n - 1;
        int right = index;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (A[mid] == target)
            {
                right = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return vector<int>({left, right});
    }
};