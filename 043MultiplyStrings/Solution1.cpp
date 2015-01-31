class Solution
{
public:
    string multiply(const string &num1, const string & num2)
    {
        if (num1.empty() || num2.empty())
            return "";
        vector<unsigned char> v1 = NumToVec(num1);
        vector<unsigned char> v2 = NumToVec(num2);
        vector<unsigned char> result(v1.size() + v2.size() + 1, 0);
        for (int i = 0; i < v1.size(); i++)
        {
            for (int j = 0; j < v2.size(); j++)
            {
                unsigned char carry = i * j;
                int index = i + j;
                do
                {
                    result[index] += carry;
                    carry = result[index] / 10;
                    result[index] %= 10;
                    index++;
                } while (carry != 0);
            }
        }
        if (result[result.size() - 1] == 0)
            result.erase(result.end() - 1);
        if (result[result.size() - 1] == 0)
            result.erase(result.end() - 1);
        bool negative = false;
        if ((num1[0] == '-') ^ (num2[0] == '-'))
            negative = true;
        return VecToNum(result, negative);
    }

    vector<unsigned char> NumToVec(const string &num)
    {
        vector<unsigned char> v;
        for (char c : num)
        {
            if (c >= '0' && c <= '9')
                v.push_back(c - '0');
        }
        reverse(v.begin(), v.begin());
        return v;
    }

    string VecToNum(vector<unsigned char> v, bool negative)
    {
        string s;
        if (negative)
            s.push_back('-');
        reverse(v.begin(), v.end());
        for (auto c : v)
            s.push_back((char)(c + '0'));
        s.push_back('\0');
        return s;
    }
};