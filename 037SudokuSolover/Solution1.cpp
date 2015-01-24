class Solution
{
public:
    struct Cell
    {
        Cell()
            : value('.')
        {
            char nums[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
            candidates.insert(nums, nums + 9);
        }
        char value;
        unordered_set<char> candidates;
    };

    Cell m_cells[9][9];
    vector<pair<int, int> > m_emptyList;

    void CopyCells(Cell dest[9][9], const Cell src[9][9])
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                dest[i][j] = src[i][j];
    }

    bool TrySolve(int index)
    {
        if (index >= m_emptyList.size())
            return true;
        int x = m_emptyList[index].first;
        int y = m_emptyList[index].second;
        Cell &c = m_cells[x][y];
        for (auto it : c.candidates)
            cout << it << " ";
        cout << endl;
        if (c.value != '.')
            return TrySolve(index + 1);

        unordered_set<char> candidates = c.candidates;
        Cell snapshot[9][9];
        CopyCells(snapshot, m_cells);
        for (auto it : candidates)
        {
            if (SetValue(x, y, it) && TrySolve(index + 1))
                    return true;
            CopyCells(m_cells, snapshot);
        }
        return false;
    }

    bool SetValue(int x, int y, char v)
    {
        Cell &c = m_cells[x][y];
        if (c.value == v)
            return true;
        if (c.candidates.find(v) == c.candidates.end())
            return false;
        c.value = v;
        c.candidates.erase(v);
        for (int i = 0; i < 9; i++)
        {
            if (i == y)
                continue;
            Cell &cc = m_cells[x][i];
            if (cc.value == v)
                return false;
            if (cc.value != '.')
                continue;
            if (cc.candidates.find(v) != cc.candidates.end())
                cc.candidates.erase(v);
            if (cc.candidates.size() == 1)
            {
                if (!SetValue(x, i, *cc.candidates.begin()))
                    return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (i == x)
                continue;
            Cell &cc = m_cells[i][y];
            if (cc.value == v)
                return false;
            if (cc.value != '.')
                continue;
            if (cc.candidates.find(v) != cc.candidates.end())
                cc.candidates.erase(v);
            if (cc.candidates.size() == 1)
            {
                if (!SetValue(i, y, *cc.candidates.begin()))
                    return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            int xx = x / 3 * 3 + i / 3;
            int yy = y / 3 * 3 + i % 3;
            if (xx == x && yy == y)
                continue;
            Cell &cc = m_cells[xx][yy];
            if (cc.value == v)
                return false;
            if (cc.value != '.')
                continue;
            if (cc.candidates.find(v) != cc.candidates.end())
                cc.candidates.erase(v);
            if (cc.candidates.size() == 1)
            {
                if (!SetValue(xx, yy, *cc.candidates.begin()))
                    return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char> > &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                    SetValue(i, j, board[i][j]);
                else
                    m_emptyList.push_back(make_pair(i, j));
            }
        }

        if (m_emptyList.empty())
            return;
            
        sort(m_emptyList.begin(), m_emptyList.end(), [&](const pair<int, int> &p1, const pair<int, int> &p2)
        {
            return m_cells[p1.first][p1.second].candidates.size() < m_cells[p2.first][p2.second].candidates.size();
        });

        if (TrySolve(0))
        {
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    board[i][j] = m_cells[i][j].value;
        }
    }
};