class Solution
{
public:
    bool isMatch(const char *s, const char *p)
    {
        if (s == NULL || p == NULL)
            return false;
        if (p[0] == '\0')
            return s[0] == '\0';
        if (p[0] == '*')
            return MatchStar(s, p + 1);
        if (s[0] == p[0] || p[0] == '?')
            return isMatch(s + 1, p + 1);
        return false;
    }
    
    bool MatchStar(const char *s, const char *p)
    {
        while (*p++ == '*')
            ;
        do
        {
            if (isMatch(s, p))
                return true;
        }
        while (*s++ != '\0');
        return false;
    }
};