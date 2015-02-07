class Solution
{
public:
    vector<vector<int> > permute(vector<int> &num)
    {
        return permute(num, num.size());
    }

    vector<vector<int> > permute(vector<int> &num, int size)
    {
        vector<std::vector<int> > v;
        if (size <= 0)
            return v;
        if (size == 1)
        {
            v.push_back(vector<int>(num.begin(), num.begin() + 1));
            return v;
        }
        
        vector<vector<int> > subV = permute(num, size - 1);
        for (auto o : subV)
        {
            for (int i = 0; i < size; i++)
            {
                vector<int> p(o.begin(), o.end());
                p.insert(p.begin() + i, num[size - 1]);
                v.push_back(p);
            }
        }
        return v;
    }
};
