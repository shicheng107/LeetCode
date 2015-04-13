class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
            v.push_back(i + 1);
        k -= 1;
        k %= getFactorial(n);
        for (int i = 0; i < k; i++)
            next_permutation(v.begin(), v.end());
        string s;
        for (int i = 0; i < n; i++)
        {
            char ss[32];
            sprintf(ss, "%d", v[i]);
            s += ss;
        }
        return s;
    }

    int getFactorial(int n)
    {
        if (n < 0)
            return 0;
        if (n <= 1)
            return 1;
        return n * getFactorial(n - 1);
    }
};
