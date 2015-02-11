namespace std
{
    template <>
    struct hash<vector<string> >
    {
        size_t operator()(const vector<string> &p) const
        {
            size_t h = 0;
            for (auto s : p)
                h ^= hash<string>()(s);
            return h;
        }
    };

    template <>
    struct equal_to<vector<string> >
    {
        bool operator()(const vector<string> &p1, const vector<string> &p2) const
        {
            if (p1.size() != p2.size())
                return false;
            for (int i = 0; i < p1.size(); i++)
                if (p1[i] != p2[i])
                    return false;
            return true;
        }
    };
}

class Solution
{
public:
    vector<vector<string> > solveNQueens(int n)
    {
        vector<int> indexes(n, 0);
        int row = 0;
        vector<string> q;
        for (int i = 0; i < n; i++)
            q.push_back(string(n, '.'));
        vector<vector<string> > result;
        stack<pair<int, int> > tries;

        int loop = 0;
        while (true)
        {
            if (row == 0 && (indexes[0] >(n + 1) / 2 || indexes[0] >= n))
                break;
            if (row >= n)
            {
                result.push_back(q);
                auto xy = tries.top();
                tries.pop();
                q[xy.first][xy.second] = '.';
                row--;
                indexes[row]++;
                continue;
            }
            if (indexes[row] >= n)
            {
                auto xy = tries.top();
                tries.pop();
                q[xy.first][xy.second] = '.';
                row--;
                indexes[row]++;
                continue;
            }
            q[row][indexes[row]] = 'Q';
            tries.push(make_pair(row, indexes[row]));
            if (IsValid(q, n, row, indexes[row]))
            {
                row++;
                if (row < n)
                    indexes[row] = 0;
            }
            else
            {
                auto xy = tries.top();
                tries.pop();
                q[xy.first][xy.second] = '.';
                indexes[row]++;
            }
        }

        unordered_set<vector<string> > m;
        for (auto o : result)
            m.insert(o);
        vector<vector<string> > otherResult;
        for (auto o : result)
        {
            auto r = Reverse(o);
            if (m.find(r) == m.end())
            {
                m.insert(r);
                otherResult.push_back(r);
            }
        }
        result.insert(result.end(), otherResult.begin(), otherResult.end());

        return result;
    }

    bool IsValid(const vector<string> &q, int n, int x, int y)
    {
        for (int i = 0; i < x; i++)
            if (q[i][y] == 'Q')
                return false;
        for (int i = 0; i < min(x, y); i++)
            if (q[x - i - 1][y - i - 1] == 'Q')
                return false;
        for (int i = 0; i < min(x, n - y - 1); i++)
            if (q[x - i - 1][y + i + 1] == 'Q')
                return false;
        return true;
    }

    void Print(const vector<string> &q)
    {
        for (auto s : q)
            cout << s << endl;
        cout << endl;
    }

    vector<string> Reverse(vector<string> &board)
    {
        vector<string> output = board;
        for (auto &s : output)
            reverse(s.begin(), s.end());
        return output;
    }
};
