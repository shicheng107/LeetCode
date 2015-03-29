struct Pt
{
    Pt(int _x, int _y) : x(_x), y(_y) {}
    int x;
    int y;
};

namespace std
{
    template <>
    struct hash<Pt>
    {
        size_t operator ()(const Pt &p) const
        {
            return hash<int>()(p.x) ^ hash<int>()(p.y);
        }
    };

    template <>
    struct equal_to<Pt>
    {
        bool operator ()(const Pt &p1, const Pt &p2) const
        {
            return p1.x == p2.x && p1.y == p2.y;
        }
    };
}

class Solution
{
public:

    enum Direction
    {
        Right = 0,
        Down = 1,
        Left = 2,
        Up = 3
    };

    vector<vector<int> > generateMatrix(int n)
    {
        vector<vector<int> > matrix;
        if (n <= 0)
            return matrix;
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j < n; j++)
                v.push_back(0);
            matrix.push_back(v);
        }

        m_direction = Right;
        m_visited.insert(Pt(0, matrix[0].size()));
        m_visited.insert(Pt(matrix.size(), matrix[0].size() - 1));
        m_visited.insert(Pt(matrix.size() - 1, -1));
        m_x = 0;
        m_y = 0;

        int size = matrix.size() * matrix[0].size();
        value = 1;
        int i = 0;
        while (i++ < size)
        {
            SetCurrent(matrix);
            GetNext(matrix, true);
        }
        return matrix;
    }

    void SetCurrent(vector<vector<int> > &matrix)
    {
        if (m_visited.find(Pt(m_x, m_y)) != m_visited.end())
            return;
        m_visited.insert(Pt(m_x, m_y));
        matrix[m_x][m_y] = value++;
    }

    void GetNext(vector<vector<int> > &matrix, bool reDirect = false)
    {
        int x = m_x;
        int y = m_y;
        switch (m_direction)
        {
        case Right:
            y++;
            if (m_visited.find(Pt(x, y)) != m_visited.end())
            {
                m_direction = Down;
                if (reDirect)
                    GetNext(matrix);
                return;
            }
            break;

        case Down:
            x++;
            if (m_visited.find(Pt(x, y)) != m_visited.end())
            {
                m_direction = Left;
                if (reDirect)
                    GetNext(matrix);
                return;
            }
            break;

        case Left:
            y--;
            if (m_visited.find(Pt(x, y)) != m_visited.end())
            {
                m_direction = Up;
                if (reDirect)
                    GetNext(matrix);
                return;
            }
            break;

        case Up:
            x--;
            if (m_visited.find(Pt(x, y)) != m_visited.end())
            {
                m_direction = Right;
                if (reDirect)
                    GetNext(matrix);
                return;
            }
            break;

        default:
            break;
        }

        m_x = x;
        m_y = y;
    }

private:
    unordered_set<Pt> m_visited;
    Direction m_direction;
    int m_x;
    int m_y;
    int value;
};
