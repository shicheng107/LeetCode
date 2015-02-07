class Solution
{
public:
    int jump(int A[], int n)
    {
        unordered_map<int, int> shortestJump;
        for (int i = 0; i < n; i++)
            shortestJump[i] = numeric_limits<int>::max();
        queue<int> reachableIndex;
        reachableIndex.push(0);
        int maxIndex = 0;
        shortestJump[0] = 0;
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
                if (shortestJump[index] + 1 < shortestJump[i])
                    shortestJump[i] = shortestJump[index] + 1;
            }
        }
        return shortestJump[n - 1];
    }
};
