class Solution
{
public:
    bool isMatch(const char *s, const char *p)
    {
        if (s == NULL || p == NULL)
            return false;
        const char *star = NULL;
        const char *starS = NULL;
        while (*s != '\0')
        {
            if (*s == *p || *p == '?')
            {
                s++;
                p++;
                continue;
            }
            if (*p == '*')
            {
                while (*p == '*') p++;
                star = p;
                starS = s;
                continue;
            }
            if (star != NULL)
            {
                p = star;
                s = ++starS;
                continue;
            }
            return false;
        }
        while (*p == '*') p++;
        return *s == '\0' && *p == '\0';
    }
};