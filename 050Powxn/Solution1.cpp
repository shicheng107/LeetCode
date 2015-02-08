class Solution
{
public:
    double pow(double x, int n)
    {
        return powInternal(x, n);
    }

private:
    double powInternal(double x, int64_t n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return powInternal(1/x, -n);
        return n % 2 == 0 ? powInternal(x * x, n / 2) : x * powInternal(x * x, (n-1) / 2);
    }
};
