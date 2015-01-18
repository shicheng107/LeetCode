class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if (n == 0) return 0;
        int index = 1;
        int last = A[0];
        for (int i = 1; i < n; i++)
        {
            if (A[i] != last)
            {
                if (i != index)
                    A[index] = A[i];
                index++;
                last = A[i];
            }
        }
        return index;
    }
};
