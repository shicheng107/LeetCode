namespace std
{
    template<>
    struct hash<unordered_set<int> >
    {
        size_t operator()(const unordered_set<int> &s)
        {
            size_t result = 0;
            for (int i : s)
                result += i * 13;
            return result;
        }
    };
    
    template<>
    struct equal_to<unordered_set<int> >
    {
        bool operator()(const unordered_set<int> &s1, const unordered_set<int> &s2)
        {
            if (s1.size() != s2.size())
                return false;
            for (int i : s1)
            {
                if (s2.find(i) == s2.end())
                    return false;
                s2.erase(i);
            }
            return s2.empty();
        }
    };
}

class Solution
{
public:
    struct SumSet
    {
        SumSet() : value(-1) {}
        
        int value;
        unordered_set<unordered_set<int> > set;
    };
    
    unordered_map<int, SumSet> m_sumSets;
    
    SumSet GetSumSet(int v, const vector<int> &candidates)
    {
        if (v <= 0)
            return SumSet();
        if (m_sumSets.find(v) != m_sumSets.end())
            return m_sumSets[v];
        SumSet result;
        result.value = v;
        for (auto i : candidates)
        {
            int left = v - i;
            if (left <= 0)
                continue;
            SumSet leftSumSet = GetSumSet(left);
            for (auto s : leftSumSet.set)
            {
                s.insert(i);
                if (result.set.find(s) == result.set.end())
                    result.set.insert(s);
            }
        }
        return result;
    }
    
    vector<vector<int> > combinationSum(const vector<int> &candidates, int target)
    {
        vector<vector<int> > result;
        for (auto i : candidates)
        {
            int left = target - i;
            if (left <= 0)
                continue;
            SumSet set = GetSumSet(left, candidates);
            vector<int> subResult(set.set.begin(), set.set.end());
            subResult.push_back(i);
            sort(subResult.begin(), subResult.end());
            if (find(result.begin(), result.end(), subResult) == result.end())
                result.push_back(subResult);
        }
        return result;
    }
};