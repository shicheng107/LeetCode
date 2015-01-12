class Solution
{
public:
    bool isMatch(const char *str, const char *reg)
    {
        if (str == NULL || reg == NULL)
            retrun false;
        if (reg[0] == '\0' && str[0] == '\0')
            return true;
        if (reg[1] == '*')
            return isMatchStart(reg[0], str, reg[2]);
        if (*str != '\0' && (reg[0] == '.' || reg[0] == str[0])
            return isMatch(str + 1, reg + 1);
        return false;
    }
    
    bool isMatchStart(char c, const char *str, const char reg)
    {
        const char *lastMatchPos = str;
        while (*lastMatchPos != '\0' && (*lastMatchPos == c || c == '.'))
            lastMatchPos++;
        do
        {
            if (isMatch(lastMatchPos, reg))
                return true;
        }
        while (lastMatchPos-- >= str);
        return false;
    }
};