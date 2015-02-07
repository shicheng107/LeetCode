class Solution
{
public:
    int jump(int A[], int n)
    {
        unordered_map<int, int> shortestJump;
        for (int i = 0; i < n; i++)
            shortestJump[i] = numeric_limits<int>::max();
        shortestJump[0] = 0;
        int index = 0;
        int maxIndex = 0;
        while (index < n)
        {
            for (int i = maxIndex + 1; i <= A[index] + index; i++)
                if (shortestJump[index] + 1 < shortestJump[i])
                    shortestJump[i] = shortestJump[index] + 1;
            index++;
        }
        return shortestJump[n - 1];
    }
};
