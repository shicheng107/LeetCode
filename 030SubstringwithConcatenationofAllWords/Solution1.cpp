class Solution 
{
public:
    vector<int> findSubstring(const string &S, vector<string> &L)
    {
        if (L.empty()) return vector<int>();
        int keywordLength = L[0].length();
        if (keywordLength == 0) return vector<int>();
        unordered_map<string, int> m;
        for (auto l : L)
            m[l]++;
        vector<int> output;
        for (int i = 0; i < S.length(); i++)
        {
            if (S.length() - i < keywordLength * L.size())
                break;
            unordered_map<string, int> keywordMap = m;
            int checkIndex = i;
            while (true)
            {
                if (keywordMap.empty())
                {
                    output.push_back(i);
                    break;
                }
                if (checkIndex > S.length() - keywordLength)
                    break;
                string toCompare = S.substr(checkIndex, keywordLength);
                if (keywordMap.find(toCompare) != keywordMap.end() && keywordMap[toCompare] > 0)
                {
                    keywordMap[toCompare]--;
                    if (keywordMap[toCompare] == 0)
                        keywordMap.erase(toCompare);
                    
                }
                else
                    break;
                checkIndex += keywordLength;
            }
        }
        return output;
    }
};
