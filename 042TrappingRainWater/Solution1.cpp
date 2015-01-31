class Solution
{
public:
    int trap(int A[], int n)
    {
        int height = 0;
        for (int i = 0; i < n; i++)
            height = max(height, A[i]);
        int trappedWater = 0;
        for (int i = 0; i < height; i++)
        {
            bool started = false;
            int water = 0;
            for (int j = 0; j < n; j++)
            {
                if (A[j] > 0)
                {
                    if (!started)
                        started = true;
                    else
                    {
                        trappedWater += water;
                        water = 0;
                    }
                }
                else if (started)
                    water++;
                A[j]--;
            }
        }
        return trappedWater;
    }
};