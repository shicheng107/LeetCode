class Solution
{
public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        vector<Interval> output;
        if (intervals.empty())
            return output;
        sort(intervals.begin(), intervals.end(), [](const Interval &it1, const Interval &it2) {return it1.start < it2.start;});
        Interval temp = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start > temp.end)
            {
                output.push_back(temp);
                temp = intervals[i];
            }
            else
            {
                if (intervals[i].end > temp.end)
                    temp.end = intervals[i].end;
            }

        }
        output.push_back(temp);
        return output;
    }
};
