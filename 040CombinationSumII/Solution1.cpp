class Solution
{
public:
    vector<vector<int> > m_result;
    vector<int> m_candidates;
    vector<int> m_temp;
    
    bool Search(int fromIndex, int target)
    {
        if (fromIndex >= m_candidates.size())
        {
            if (target == 0)
            {
                vector<int> result(m_temp.begin(), m_temp.end());
                reverse(result.begin(), result.end());
                if (find(m_result.begin(), m_result.end(), result) == m_result.end())
                    m_result.push_back(result);
            }
            return true;
        }
        if (m_candidates[fromIndex] > target)
            return Search(fromIndex + 1, target);
        
        {
            m_temp.push_back(m_candidates[fromIndex]);
            int left = target - m_candidates[fromIndex];
            Search(fromIndex + 1, left);
            m_temp.pop_back();
        }
        
        {
            Search(fromIndex + 1, target);
        }
        return true;
    }
    
    vector<vector<int> > combinationSum(const vector<int> &candidates, int target)
    {
        m_candidates.assign(candidates.begin(), candidates.end());
        sort(m_candidates.begin(), m_candidates.end(), [](int a, int b){return a > b; });
        
        Search(0, target);
        
        return m_result;
    }
};