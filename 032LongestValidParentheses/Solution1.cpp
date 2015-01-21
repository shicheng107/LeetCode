class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int longest = 0;
        // dp is the longest length of valid parentheses ending at i.
        vector<int> dp(s.size(), 0);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || i == 0)
                continue;
            int j = i - 1 - dp[i-1];
            if (j >= 0 && s[j] == '(')
            {
                dp[i] = dp[i-1] + 2;
                if (--j > 0 && dp[j] > 0)
                    dp[i] += dp[j];
            }
            longest = max(longest, dp[i]);
        }
        return longest;
    }
};