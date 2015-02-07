namespace std
{
    template<>
    struct hash<vector<int> >
    {
        std::size_t operator()(const vector<int> &num) const
        {
            size_t h = 0;
            for (auto n : num)
                h ^= std::hash<int>()(n);
            return h;
        }
    };

    template<>
    struct equal_to<vector<int> >
    {
        bool operator()(const vector<int> &num1, const vector<int> &num2) const
        {
            if (num1.size() != num2.size())
                return false;
            for (int i = 0; i < num1.size(); i++)
                if (num1[i] != num2[i])
                    return false;
            return true;
        }
    };
}

class Solution
{
public:
    vector<vector<int> > permuteUnique(vector<int> &num)
    {
        return permuteUnique(num, num.size());
    }

    vector<vector<int> > permuteUnique(vector<int> &num, int size)
    {
        vector<std::vector<int> > v;
        if (size <= 0)
            return v;
        if (size == 1)
        {
            v.push_back(vector<int>(num.begin(), num.begin() + 1));
            return v;
        }
        
        auto subV = permuteUnique(num, size - 1);
        unordered_set<vector<int> > s;
        for (auto o : subV)
        {
            for (int i = 0; i < size; i++)
            {
                vector<int> p(o.begin(), o.end());
                p.insert(p.begin() + i, num[size - 1]);
                if (s.find(p) != s.end())
                    continue;
                s.insert(p);
                v.push_back(p);
            }
        }
        return v;
    }
};
