class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        if (board.size() != 9)
            return false;
        for (auto v : board)
            if (v.size() != 9)
                return false;
        char nums[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        unordered_set<char> st(nums, nums + 9);
        
        // Check row.
        for (int i = 0; i < 9; i++)
        {
            unordered_set<char> s = st;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (s.find(board[i][j]) == s.end())
                    return false;
                s.erase(board[i][j]);
            }
        }
        
        // Check column.
        for (int i = 0; i < 9; i++)
        {
            unordered_set<char> s = st;
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.')
                    continue;
                if (s.find(board[j][i]) == s.end())
                    return false;
                s.erase(board[j][i]);
            }
        }
        
        // Check each block.
        for (int i = 0; i < 9; i++)
        {
            unordered_set<char> s = st;
            for (int j = 0; j < 9; j++)
            {
                int x = i / 3 * 3 + j / 3;
                int y = (i * 3 + j % 3) % 9;
                if (board[x][y] == '.')
                    continue;
                if (s.find(board[x][y]) == s.end())
                    return false;
                s.erase(board[x][y]);
            }
        }
        return true;
    }
};