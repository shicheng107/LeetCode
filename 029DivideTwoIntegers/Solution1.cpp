class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == 0)
            return 0;
        int64_t a = static_cast<int64_t>(dividend);
        int64_t b = static_cast<int64_t>(divisor);
        bool negative = a > 0 && b < 0 || a < 0 && b > 0;
        a = abs(a);
        b = abs(b);
        int64_t result = 0;
        while (a >= b)
        {
            int64_t temp = b;
            int count = 0;
            while (a >= temp)
            {
                temp <<= 1;
                count++;
            }
            count--;
            a -= temp >> 1;
            result += 1LL << count;
        }
        result = negative ? -result : result;
        if (result > numeric_limits<int32_t>::max())
            result = numeric_limits<int32_t>::max();
        else if (result < numeric_limits<int32_t>::min())
            result = numeric_limits<int32_t>::min();
        return static_cast<int32_t>(result);
    }
};