class Solution
{
public:
    bool canJump(int A[], int n)
    {
        queue<int> reachableIndex;
        reachableIndex.push(0);
        int maxIndex = 0;
        while (!reachableIndex.empty())
        {
            int index = reachableIndex.front();
            reachableIndex.pop();
            for (int i = maxIndex + 1; i <= A[index] + index; i++)
            {
                if (i >= n)
                    break;
                reachableIndex.push(i);
                maxIndex = i;
                if (maxIndex == n - 1)
                    return true;
            }
        }
        return maxIndex == n - 1;
    }
};
