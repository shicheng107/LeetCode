class Solution
{
public:
    int lengthOfLastWord(const char *s)
    {
        if (s == NULL)
            return 0;
        bool started = false;
        int length = strlen(s);
        int lastWordLength = 0;
        for (int i = length - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (!started)
                    continue;
                else
                    break;
            }
            started = true;
            lastWordLength++;
        }
        return lastWordLength;
    }
};
