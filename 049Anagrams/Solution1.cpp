class Solution
{
public:
    vector<vector<string> > anagrams(vector<string> &strs)
    {
        unordered_map<string, vector<int> > m;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(i);
        }
        vector<vector<string> > output;
        for (auto o : m)
        {
            if (o.second.empty())
                continue;
            vector<string> subOutput;
            for (auto p : o.second)
                subOutput.push_back(strs[p]);
            output.push_back(subOutput);
        }

        return output;
    }
};
