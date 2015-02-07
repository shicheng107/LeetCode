class Solution

{

public:

    vector<vector<int> > permute(vector<int> &num)

    {

        vector<std::vector<int> > v;

        sort(num.begin(), num.end());

        do

        {

            v.push_back(num);

        }

        while (next_permutation(num.begin(), num.end()));

        return v;

    }

};
