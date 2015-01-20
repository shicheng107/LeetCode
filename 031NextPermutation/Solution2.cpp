class Solution
{
public:
    void nextPermutation(vector<int> &num)
    {
        int left = -1;
        for (int i = num.size() - 1; i > 0; i--)
        {
            if (num[i - 1] < num[i])
            {
                left = i - 1;
                break;
            }
        }
        if (left == -1)
        {
            reverse(num.begin(), num.end());
            return;
        }
        for (int i = num.size() - 1; i > left; i--)
        {
            if (num[i] > num[left])
            {
                swap(num[i], num[left]);
                reverse(num.begin() + left + 1, num.end());
                return;
            }
        }
    }
};
