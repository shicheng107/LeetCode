class Solution
{
public:
    int strStr(char *haystack, char *needle)
    {
        if (haystack == NULL || needle == NULL)
            return -1;
        int length = strlen(haystack);
        int needleLength = strlen(needle);
        if (length < needleLength)
            return -1;
        length = length - needleLength + 1;
        for (int i = 0; i < length; i++)
        {
            bool found = true;
            for (int j = 0; j < needleLength; j++)
            {
                if (haystack[i+j] != needle[j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
                return i;
        }
        return -1;
    }
};
