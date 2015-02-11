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

        while (true)
        {
            if (row == 0 && indexes[0] >= n)
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
            if (q[x -i - 1][y + i + 1] == 'Q')
                return false;
        return true;
    }
};
