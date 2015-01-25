class Solution
{
public:
    string countAndSay(int n)
    {
        if (n <= 0)
            return "";
        string s;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                s = "1";
                continue;
            }
            int index = 0;
            string newS;
            char last = '\0';
            char count = '0';
            for (auto c : s)
            {
                if (c != last)
                {
                    if (count > '0')
                    {
                        newS.push_back(count);
                        newS.push_back(last);
                    }
                    last = c;
                    count = '1';
                }
                else
                    count++;
            }
            if (count > '0')
            {
                newS.push_back(count);
                newS.push_back(last);
            }
            s = newS;
        }
        return s;
    }
};